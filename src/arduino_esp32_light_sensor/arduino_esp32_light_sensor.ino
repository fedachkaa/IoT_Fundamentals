const int lightPin = A1;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int lightValue = analogRead(lightPin);
  Serial.println(lightValue);
  delay(1000);
}
