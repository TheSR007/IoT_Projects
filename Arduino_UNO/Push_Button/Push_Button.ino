// Push Button (Digital Input)
#define BUTTON_PIN 2  // Push Button connected to digital pin 2

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);  // Setting the button pin as input
  Serial.begin(9600);
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);  // Reading the button state
  if (buttonState == LOW) {
    Serial.println("Button Pressed!");
  } else {
    Serial.println("Button Not Pressed");
  }
  delay(200);
}
