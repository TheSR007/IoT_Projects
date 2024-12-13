// Buzzer or Led (Digital Output)
#define OUTPUT_PIN 2  // Output Component is connected to digital pin 2

void setup() {
  pinMode(OUTPUT_PIN, OUTPUT);  // Setting the OUTPUT pin as output
}

void loop() {
  digitalWrite(OUTPUT_PIN, HIGH);  // Turn the OUTPUT on
  delay(1000);
  digitalWrite(OUTPUT_PIN, LOW);  // Turn the OUTPUT off
  delay(1000);
}
