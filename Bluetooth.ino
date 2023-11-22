#include <SoftwareSerial.h>

SoftwareSerial BTserial(8, 9);

const int temp_pin = A0;
const int dist_pin = A1;
const int signal_pin = A2;
const int noise_pin = A3; 
const int dist_power = 12;
const int presence_power = 11;
const int noise_power = 10;

int detect = 500;
int counter = 1; 

void setup() {
  pinMode(dist_pin, INPUT);
  pinMode(temp_pin, INPUT);
  pinMode(signal_pin, INPUT);
  pinMode(dist_power, OUTPUT);
  pinMode(presence_power, OUTPUT);
  pinMode(noise_power, OUTPUT);
  pinMode(2, OUTPUT); //red
  pinMode(3, OUTPUT); //yellow
  pinMode(4, OUTPUT); //green 
  pinMode(7, OUTPUT);
  Serial.begin(9600);
  BTserial.begin(9600);
}

double fixtemp = 20.0;

double Thermistor(int RawADC) {
  return 20.0 - (RawADC - 560) / 5.7;
}

void traffic_light(int i, int j, int k) {
  digitalWrite(i, LOW);
  digitalWrite(j, LOW);
  digitalWrite(k, HIGH);
}

void loop() {
  while (BTserial.available() == 0) {}
  String command = BTserial.readString();
  command.trim();
  if (command == "temp") {
    while (command != "no") {
      traffic_light(4, 3, 2);
      BTserial.print("The space temperature = "); 
      BTserial.println(Thermistor(analogRead(temp_pin)));
      delay(2000);
      command = BTserial.readString();
    }
  } else if (command == "dist") {
      while (command != "no") {
          digitalWrite(dist_power, HIGH);
          if (analogRead(dist_pin) < detect) {
            BTserial.print("Object has been detected. A number of detections = ");
            BTserial.println(counter);
            counter += 1;
            traffic_light(4, 3, 2);
            delay(8000);
          } else {
            traffic_light(2, 3, 4);
          }
          command = BTserial.readString();
      }
  } else if (command == "presence") { // датчик присутсвия 
      while (command != "no") {
        digitalWrite(presence_power, HIGH);
        if (digitalRead(signal_pin) == HIGH) {
          traffic_light(4, 3, 2);
          BTserial.println("Detected.");
          tone(7, 2000);
        } else {
          traffic_light(2, 3, 4);
          BTserial.println("No detected.");  
          noTone(7);
        }
        command = BTserial.readString();
        delay(1000);
      }
      noTone(7);
  } else if (command == "noise") {
      while (command != "no") {
        digitalWrite(noise_pin, HIGH);
        BTserial.print("Level noises : ");
        int read = 0;
        read = analogRead(noise_pin);
        BTserial.println(read);
        delay(500);
        if (read  < 40 ) { 
          traffic_light(2, 3, 4);
        } else if (read < 300) { 
          traffic_light(2, 4, 3);
          
        } else {
          traffic_light(4, 3, 2); 
        }
        command = BTserial.readString();
      }
  }
  else {
    traffic_light(2, 3, 4);
  }
}
