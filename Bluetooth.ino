#include <SoftwareSerial.h>

SoftwareSerial BTserial(8, 9); // rxd and txd

const int temp_pin = 0;
const int dist_pin = 1;
const int dist_power = 12;
const int signal_pin = 5;
const int lees = A0; 
int detect = 500; // значение, которое датчик выдаёт при засечение предмета равно порядка 200
int counter = 1; 
// пин 9 занят пищалкой //

void setup() {
  pinMode(lees, INPUT);
  pinMode(temp_pin, OUTPUT);
  pinMode(signal_pin, INPUT); // пин для датчика присутсвия
  // put your setup code here, to run once:
  Serial.begin(9600);
  BTserial.begin(9600);
  pinMode(2, OUTPUT); //red
  pinMode(3, OUTPUT); //yellow
  pinMode(4, OUTPUT); //green
}

double fixtemp = 20.0;

double Thermistor(int RawADC) // convert voltage to temperature celsius
{
  Serial.println(RawADC);
  return 20.0 - (RawADC - 560) / 5.7;
}

void loop() {
  // put your main code here, to run repeatedly:
  while (BTserial.available() == 0) {} // while nothing to read
  String command = BTserial.readString();
  command.trim();
  if (command == "temp"){
    digitalWrite(3, LOW); // traffic light
    digitalWrite(4, LOW);
    digitalWrite(2, HIGH);
    Serial.print("The space temperature = "); 
    Serial.println(Thermistor(analogRead(temp_pin)));
  } else if (command == "dist"){
      if (analogRead(lees) < detect) {
        Serial.print("Объект обнаружен. Количесвто обнаружений = ");
        Serial.println(counter);
        counter += 1;
        digitalWrite(4, LOW);
        digitalWrite(3, LOW);
        digitalWrite(2, HIGH);
        delay(8000);
      } else {
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, HIGH);
      }
  } else if (command == 'presence'){ // датчик присутсвия 
      if (digitalRead(signal_pin) == HIGH) {
        digitalWrite(4, LOW); // горит красный, если что-то есть 
        digitalWrite(3, LOW);
        digitalWrite(2, HIGH); 
        Serial.println("Обнаружен."); // можно вывести на телефон
        tone(9, 2000); // пищим, если что-то есть
      } else {
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, HIGH);
        Serial.println("Не обнаружен."); 
        noTone(9);
      }
      delay(1000);
  } else if (command == 'noise') {
      Serial.print("Уровень шума : ");
      Serial.println(analogRead(lees));
      delay(500);
      if ((analogRead(analog))  < 40 ) { // порог срабатывания зелёного светодиода, мВ по дефолту в тишине меньше 40
        digitalWrite(4, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(2, LOW);
      } else if ((analogRead(analog)) < 300) { // порог срабатывания жёлтого светодиода, мВ
        digitalWrite(4, LOW);
        digitalWrite(3, HIGH);
        digitalWrite(2, LOW);
      } else { // порог срабатывания красного светодиода, мВ
        digitalWrite(4, LOW);
        digitalWrite(3, LOW);
        digitalWrite(2, HIGH);    
      }
  }
  else{
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
  }
}
