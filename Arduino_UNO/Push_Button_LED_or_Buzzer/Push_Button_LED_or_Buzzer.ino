// Push Button and Led orBuzzer
#define BUTTON_PIN 3  // Push button connected to digital pin 2
#define OUTPUT_PIN 8  // Buzzer connected to digital pin 3

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);   // Setting the button pin as input
  pinMode(OUTPUT_PIN, OUTPUT);  // Setting the buzzer pin as output
  Serial.begin(9600);
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);  // Read the state of the button
  if (buttonState == LOW) {
    digitalWrite(OUTPUT_PIN, HIGH);  // Turn buzzer on if button is pressed
  } else {
    digitalWrite(OUTPUT_PIN, LOW);   // Turn buzzer off if button is not pressed
  }
  Serial.print("ButtonState: ");
  Serial.println(buttonState);
  delay(200);
}
