// IR Sensor (Digital Input)
#define IR_PIN 2  // IR sensor connected to digital pin 2

void setup() {
  pinMode(IR_PIN, INPUT);  // Setting the IR pin as input
  Serial.begin(9600);
}

void loop() {
  int irValue = digitalRead(IR_PIN);  // Read the IR sensor state
  if (irValue == Low) {
    Serial.println("IR Signal Detected!");
  } else {
    Serial.println("No IR Signal");
  }
  delay(500);
}
