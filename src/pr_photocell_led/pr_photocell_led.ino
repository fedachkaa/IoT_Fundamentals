int ledPin = 5;
int val = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); 
}

void loop() {
  val = analogRead(A1); 
  Serial.println(val);
  if (val < 900) {
    digitalWrite(ledPin, LOW);
  } else {
    digitalWrite(ledPin, HIGH);
  }
  delay(10);
}
