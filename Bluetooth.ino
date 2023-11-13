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

}

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available()) {}
  String command = BTserial.readString();
  command.trim();
  if (command == "temp"){
    Serial.print(analogRead(temp_pin));
  } else if (command == "dist"){
    digitalWrite(dist_power, HIGH);
    Serial.print(analogRead(dist_pin));
    digitalWrite(dist_power, LOW);
  } else{
    // nothing
  }
}
