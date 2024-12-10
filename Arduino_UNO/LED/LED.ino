// LED (Digital Output)
#define LED_PIN 2  // LED connected to digital pin 2

void setup() {
  pinMode(LED_PIN, OUTPUT);  // Setting the LED pin as output
}

void loop() {
  digitalWrite(LED_PIN, HIGH);  // Turn the LED on
  delay(1000);
  digitalWrite(LED_PIN, LOW);  // Turn the LED off
  delay(1000);
}
