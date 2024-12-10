// Ultrasonic Sensor (Distance Measurement)
#define TRIGGER_PIN 2  // Trigger pin of the ultrasonic sensor
#define ECHO_PIN 3     // Echo pin of the ultrasonic sensor

void setup() {
  pinMode(TRIGGER_PIN, OUTPUT);  // Setting trigger pin as output
  pinMode(ECHO_PIN, INPUT);      // Setting echo pin as input
  Serial.begin(9600);
}

void loop() {
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);  // Measure the pulse width
  long distance = duration * 0.03427 / 2;   // Calculate distance in cm

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(500);
}
