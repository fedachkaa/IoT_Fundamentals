// C++ code

// This example uses a button to control a while loop.
// The program will turn LEDs on and off one by one in a loop until the button is pressed.

const int RED_LED = 5;
const int YELLOW_LED = 4;
const int GREEN_LED = 3;
const int BUTTON_PIN = 2;
int ledPins[] = {RED_LED, YELLOW_LED, GREEN_LED};
unsigned long previousMillis = 0;
const unsigned long interval = 500;
bool isLightsOn = true;

void setup() {
  pinMode(BUTTON_PIN, INPUT);
  for (int i = 0; i < 3; i++) {
    pinMode(ledPins[i], OUTPUT);
  } 
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), toggleLights, RISING);
}

void loop() {
  int counter = 0;
  while (isLightsOn) {
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval) {
      turnOffLeds();
      digitalWrite(ledPins[counter], HIGH);
      counter = (counter + 1) % 3;
      previousMillis = currentMillis;
    }
  }
}

void toggleLights() {
  isLightsOn = !isLightsOn;
  turnOffLeds();
}

void turnOffLeds() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(ledPins[i], LOW);
  }
}