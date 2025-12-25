// C++ code
// When the button is not pressed, all LEDs are turned off.
// When the button is pressed for the first time, the red LED lights up.
// On the second press, the yellow LED lights up, and the red LED turns off.
// On the third press, the green LED lights up, and the yellow LED turns off.
// On the fourth press, all LEDs turn off again.

const int RED_LED = 5;
const int YELLOW_LED = 4;
const int GREEN_LED = 3;
const int BUTTON_PIN = 2;
int ledPins[] = {RED_LED, YELLOW_LED, GREEN_LED};
int counter = 0;
bool lastButtonState = LOW;

void setup() {
  pinMode(BUTTON_PIN, INPUT);
  for (int i = 0; i < 3; i++) {
    pinMode(ledPins[i], OUTPUT);
  } 
}

void loop() {
  bool currentButtonState = digitalRead(BUTTON_PIN);

  if (currentButtonState == HIGH && lastButtonState == LOW) {
    counter++;

    for (int i = 0; i < 3; i++) {
      digitalWrite(ledPins[i], LOW);
    }
    
    switch(counter) {
      case 1:
      	digitalWrite(RED_LED, HIGH);
      	break;
      case 2:
      	digitalWrite(YELLOW_LED, HIGH);
      	break;
      case 3:
      	digitalWrite(GREEN_LED, HIGH);
      	break;
      default:
      	counter = 0;
    }
  }

  lastButtonState = currentButtonState;
}