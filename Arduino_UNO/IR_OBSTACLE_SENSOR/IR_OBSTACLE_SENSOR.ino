// IR Sensor (Digital Input)
#define IR_PIN 2  // IR sensor connected to digital pin 2
#define BUZZER_PIN 3  // IR sensor connected to digital pin 2

void setup() {
  pinMode(IR_PIN, INPUT);  // Setting the IR pin as input
  pinMode(BUZZER_PIN, OUTPUT);  // Setting the IR pin as input
  Serial.begin(9600);
}

void loop() {
  int irValue = digitalRead(IR_PIN);  // Read the IR sensor state
  if (irValue == LOW) {
    Serial.println("Obstacle detected!");
    digitalWrite(BUZZER_PIN, HIGH);
  } else {
    Serial.println("No Obstacle detected");
    digitalWrite(BUZZER_PIN, LOW);
  }
  delay(150);
}
