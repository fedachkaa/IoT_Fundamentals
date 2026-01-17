#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include "secrets.h"

int lightValue = 0;

BlynkTimer timer;

void setup()
{
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, 14, 12);
  Blynk.begin(BLYNK_AUTH_TOKEN, WIFI_SSID, WIFI_PASS);
  
  timer.setInterval(180000L, readArduino);
}

void loop()
{
  Blynk.run();
  timer.run();
}

void readArduino() 
{
  while (Serial2.available()) {
    String val = Serial2.readStringUntil('\n');
    val.trim();
    lightValue = val.toInt();
    Blynk.virtualWrite(V1, lightValue);
    Serial.println("Received: " + String(lightValue));
  }
}
