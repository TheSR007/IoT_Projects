// Pin Definitions
#define BUTTON = 2;        // Push button pin
const int ledPins[] = {3, 4, 5, 6, 7, 8}; // LED pins

int buttonState = 0;            // Current state of the button
int lastButtonState = 0;        // Previous state of the button

void setup() {
  // Set LED pins as output
  for (int i = 0; i < 6; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  
  // Set button pin as input
  pinMode(BUTTON, INPUT_PULLUP);

  // Initialize all LEDs as OFF
  for (int i = 0; i < 6; i++) {
    digitalWrite(ledPins[i], LOW);
  }

  Serial.begin(9600); // For debugging purposes
}

void loop() {
  // Read the state of the button
  buttonState = digitalRead(BUTTON);

  // Check if the button is pressed (and debounce)
  if (buttonState == HIGH && lastButtonState == LOW) {
    delay(50); // Debounce delay
    if (digitalRead(BUTTON) == HIGH) {
      int diceValue = random(1, 7); // Generate random number between 1 and 6
      showDice(diceValue);          // Display the corresponding dice pattern
      Serial.println(diceValue);   // Print the dice value for debugging
    }
  }

  lastButtonState = buttonState; // Update the last button state
}

void showDice(int value) {
  // Turn off all LEDs initially
  for (int i = 0; i < 6; i++) {
    digitalWrite(ledPins[i], LOW);
  }

  // Turn on LEDs based on dice value
  switch (value) {
    case 1:
      digitalWrite(ledPins[2], HIGH); // Center
      break;
    case 2:
      digitalWrite(ledPins[0], HIGH); // Top left
      digitalWrite(ledPins[5], HIGH); // Bottom right
      break;
    case 3:
      digitalWrite(ledPins[0], HIGH); // Top left
      digitalWrite(ledPins[2], HIGH); // Center
      digitalWrite(ledPins[5], HIGH); // Bottom right
      break;
    case 4:
      digitalWrite(ledPins[0], HIGH); // Top left
      digitalWrite(ledPins[1], HIGH); // Top right
      digitalWrite(ledPins[4], HIGH); // Bottom left
      digitalWrite(ledPins[5], HIGH); // Bottom right
      break;
    case 5:
      digitalWrite(ledPins[0], HIGH); // Top left
      digitalWrite(ledPins[1], HIGH); // Top right
      digitalWrite(ledPins[2], HIGH); // Center
      digitalWrite(ledPins[4], HIGH); // Bottom left
      digitalWrite(ledPins[5], HIGH); // Bottom right
      break;
    case 6:
      digitalWrite(ledPins[0], HIGH); // Top left
      digitalWrite(ledPins[1], HIGH); // Top right
      digitalWrite(ledPins[2], HIGH); // Top right
      digitalWrite(ledPins[3], HIGH); // Middle left
      digitalWrite(ledPins[4], HIGH); // Bottom left
      digitalWrite(ledPins[5], HIGH); // Bottom right
      break;
  }
}
