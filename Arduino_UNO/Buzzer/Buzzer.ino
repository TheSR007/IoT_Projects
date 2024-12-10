// Buzzer (Digital Output)
#define BUZZER_PIN 2  // Buzzer connected to digital pin 2

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);  // Setting the BUZZER pin as output
}

void loop() {
  digitalWrite(BUZZER_PIN, HIGH);  // Turn the BUZZER on
  delay(1000);
  digitalWrite(BUZZER_PIN, LOW);  // Turn the BUZZER off
  delay(1000);
}
