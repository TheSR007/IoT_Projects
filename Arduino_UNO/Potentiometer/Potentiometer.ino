// Potentiometer (Analog Input)
#define POT_PIN A0  // Potentiometer connected to analog pin A0
#define POT_MAX 1023 // Max value of Potentiometer
#define START 0 // Desired Starting Value
#define END 1023 // Desired End Value

void setup() {
  Serial.begin(9600);
}

void loop() {
  int potValue = analogRead(POT_PIN);  // Reading the potentiometer value
  Serial.print("Potentiometer Value: ");
  Serial.print(potValue);
  potValue = map(potValue, 0, POT_MAX, START, END);
  Serial.print(" | Desired Value: ");
  Serial.println(potValue);
  delay(200);
}
