// Push Button and Buzzer
#define BUTTON_PIN 2  // Push button connected to digital pin 2
#define BUZZER_PIN 3  // Buzzer connected to digital pin 3

void setup() {
  pinMode(BUTTON_PIN, INPUT);   // Setting the button pin as input
  pinMode(BUZZER_PIN, OUTPUT);  // Setting the buzzer pin as output
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);  // Read the state of the button
  if (buttonState == HIGH) {
    digitalWrite(BUZZER_PIN, HIGH);  // Turn buzzer on if button is pressed
  } else {
    digitalWrite(BUZZER_PIN, LOW);   // Turn buzzer off if button is not pressed
  }
}
