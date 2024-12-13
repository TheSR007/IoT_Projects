// Push Button and Led orBuzzer
#define BUTTON 2  // Push button connected to digital pin 2
#define OUTPUT 3  // Buzzer connected to digital pin 3

void setup() {
  pinMode(BUTTON, INPUT_PULLUP);   // Setting the button pin as input
  pinMode(OUTPUT, OUTPUT);  // Setting the buzzer pin as output
  Serial.begin(9600);
}

void loop() {
  int buttonState = digitalRead(BUTTON);  // Read the state of the button
  if (buttonState == LOW) {
    digitalWrite(OUTPUT, HIGH);  // Turn buzzer on if button is pressed
    delay(5000);
  } else {
    digitalWrite(OUTPUT, LOW);   // Turn buzzer off if button is not pressed
  }
  Serial.print("ButtonState: ");
  Serial.println(buttonState);
  delay(200);
}
