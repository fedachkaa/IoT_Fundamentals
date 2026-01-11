#include <SoftwareSerial.h>

SoftwareSerial bluetooth(11, 10);
const int ledPin = 13;

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
  pinMode(ledPin, OUTPUT);
  Serial.println("Система керування світлодіодом готова");
}

void loop() {
  if (bluetooth.available()) {
    char command = bluetooth.read();

    if (command == '1') {
      digitalWrite(ledPin, HIGH);
      bluetooth.println("LED ON");
      Serial.println("LED увімкнено");
    } else if (command == '0') {
      digitalWrite(ledPin, LOW);
      bluetooth.println("LED OFF");
      Serial.println("LED вимкнено");
    }
  }
}