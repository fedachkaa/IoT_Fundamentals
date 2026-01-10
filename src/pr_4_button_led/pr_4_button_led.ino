int ledPin = 5;
int buttonPin = 4;
int val;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  val = digitalRead(buttonPin);
  digitalWrite(ledPin, !val);
}
