// Ultrasonic Sensor (Distance Measurement)
#define TRIGGER 2  // Trigger pin of the ultrasonic sensor
#define ECHO 3     // Echo pin of the ultrasonic sensor
#define BUZZER 4
#define LED 6

void setup() {
  pinMode(TRIGGER, OUTPUT);  // Setting trigger pin as output
  pinMode(ECHO, INPUT);      // Setting echo pin as input
  pinMode(BUZZER, OUTPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(TRIGGER, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER, LOW);

  long duration = pulseIn(ECHO, HIGH);  // Measure the pulse width
  long distance = duration * 0.03427 / 2;   // Calculate distance in cm

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  if(distance < 16)
    digitalWrite(BUZZER, HIGH);
  else
    digitalWrite(BUZZER, LOW);

  if(distance < 31)
    digitalWrite(LED, HIGH);
  else
    digitalWrite(LED, LOW);
}
