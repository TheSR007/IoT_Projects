// Push Button and LED
#define BUTTON_PIN 2  // Push button connected to digital pin 2
#define LED_PIN 3     // LED connected to digital pin 3

void setup() {
  pinMode(BUTTON_PIN, INPUT);  // Setting the button pin as input
  pinMode(LED_PIN, OUTPUT);    // Setting the LED pin as output
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);  // Read the state of the button
  if (buttonState == HIGH) {
    digitalWrite(LED_PIN, HIGH);  // Turn LED on if button is pressed
  } else {
    digitalWrite(LED_PIN, LOW);   // Turn LED off if button is not pressed
  }
}
