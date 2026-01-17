#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int soilSensorPin = A2;
volatile int value;
LiquidCrystal_I2C mylcd (0x27,16,2);

void setup() {
  Serial.begin(9600);
  value = 0;
  Wire.begin();
  mylcd.init();
  mylcd.backlight();
  mylcd.clear();
  pinMode(soilSensorPin, INPUT);
}

void loop() {
  Serial.print("Soil moisture value:");
  Serial.println(value);
  delay(500);
  value = analogRead(soilSensorPin);
  if (value < 300) {
    displayText(value, "Dry soil");
  } else if ((value >= 300) && (value <= 700)) {
    displayText(value, "Humid soil");
  } else {
    displayText(value, "In water");
  }
  delay(300); 
}

void displayText(int value, const char* text) {
  mylcd.clear();
  mylcd.setCursor(0, 0);
  mylcd.print("Value:");
  mylcd.setCursor(6, 0);
  mylcd.print(value);
  mylcd.setCursor(0, 1);
  mylcd.print(text);
}
