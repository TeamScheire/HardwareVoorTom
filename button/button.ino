#define BUTTON0_PIN 0
#define LED_PORT 1
int buttonPressed = 0;
int buttonStatus = 0;

#define SPEAKER_PIN 2

void setup() {
  pinMode(BUTTON0_PIN, INPUT_PULLUP);
  
  pinMode(SPEAKER_PIN, OUTPUT);
  pinMode(LED_PORT, OUTPUT);
}

void loop() {
  if (checkButtonPressed()) {
    buttonStatus = 1 - buttonStatus;
  }

  if (buttonStatus) {
    digitalWrite(SPEAKER_PIN, HIGH);
    digitalWrite(LED_PORT, HIGH);
  } else {
    digitalWrite(SPEAKER_PIN, LOW);
    digitalWrite(LED_PORT, LOW);
  }

  delay(10);
}

bool checkButtonPressed() {
  int currentValue = digitalRead(BUTTON0_PIN);
  
  if ((currentValue == LOW) && (buttonPressed == 0)) {
    buttonPressed = 1;
    return true;
  }
  if (currentValue == HIGH) {
    buttonPressed = 0;
  }
  return false;
}
