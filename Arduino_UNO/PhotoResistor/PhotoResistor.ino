// PhotoResistor (Digital Input)
#define LDR_PIN 2  // IR sensor connected to digital pin 2

void setup() {
  pinMode(LDR_PIN, INPUT);  // Setting the IR pin as input
  Serial.begin(9600);
}

void loop() {
  int LDRState = digitalRead(LDR_PIN);  // Read the IR sensor state
  if (LDRState == HIGH) {
    Serial.println("Object Detected!");
  } else {
    Serial.println("No Object");
  }
  delay(200);
}
