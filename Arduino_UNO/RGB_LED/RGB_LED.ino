// LED (Digital Output)
#define RED_LED_PIN 2  // LED connected to digital pin 2
#define GREEN_LED_PIN 3
#define BLUE_LED_PIN 4

void setup() {
  pinMode(RED_LED_PIN, OUTPUT);  // Setting the Red LED pin as output
  pinMode(GREEN_LED_PIN, OUTPUT);  // Setting the Green LED pin as output
  pinMode(BLUE_LED_PIN, OUTPUT);  // Setting the Blue LED pin as output
}

void loop() {
  digitalWrite(RED_LED_PIN, HIGH);  // Turn the LED on
  delay(300);
  digitalWrite(RED_LED_PIN, LOW);  // Turn the LED off
  delay(300);  
  digitalWrite(GREEN_LED_PIN, HIGH);  // Turn the LED on
  delay(300);
  digitalWrite(GREEN_LED_PIN, LOW);  // Turn the LED off
  delay(300);
  digitalWrite(BLUE_LED_PIN, HIGH);  // Turn the LED on
  delay(300);
  digitalWrite(BLUE_LED_PIN, LOW);  // Turn the LED off
  delay(300);
  digitalWrite(RED_LED_PIN, HIGH);  // Turn the LED on
  digitalWrite(GREEN_LED_PIN, HIGH);  // Turn the LED on
  delay(300);
  digitalWrite(RED_LED_PIN, LOW);  // Turn the LED off
  digitalWrite(GREEN_LED_PIN, LOW);  // Turn the LED off
  delay(300);  
  digitalWrite(GREEN_LED_PIN, HIGH);  // Turn the LED on
  digitalWrite(BLUE_LED_PIN, HIGH);  // Turn the LED on
  delay(300);
  digitalWrite(GREEN_LED_PIN, LOW);  // Turn the LED off
  digitalWrite(BLUE_LED_PIN, LOW);  // Turn the LED off
  delay(300);
  digitalWrite(BLUE_LED_PIN, HIGH);  // Turn the LED on
  digitalWrite(RED_LED_PIN, HIGH);  // Turn the LED on
  delay(300);
  digitalWrite(BLUE_LED_PIN, LOW);  // Turn the LED off
  digitalWrite(RED_LED_PIN, LOW);  // Turn the LED off
  delay(300);
}
