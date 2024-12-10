// Potentiometer (Analog Input)
#define POT_PIN A0  // Potentiometer connected to analog pin A0

void setup() {
  Serial.begin(9600);
}

void loop() {
  int potValue = analogRead(POT_PIN);  // Reading the potentiometer value (0-1023)
  Serial.print("Potentiometer Value: ");
  Serial.println(potValue);
  delay(500);
}
