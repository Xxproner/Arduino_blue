#include <SoftwareSerial.h>

SoftwareSerial BTserial(8, 9); // rxd and txd

const int temp_pin = 0;
const int dist_pin = 1;
const int dist_power = 12;

void setup() {
  pinMode(temp_pin, OUTPUT);
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
    digitalWrite(2, LOW);
    digitalWrite(4, LOW);
    digitalWrite(3, HIGH);
    Serial.print("The distance ... = "); 
    Serial.println(analogRead(dist_pin)); 
  } else{
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
  }
}
