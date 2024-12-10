#include <ESP32Servo.h>  // Use ESP32Servo Servo library

Servo servo;

int ServoPin = 4;
int angle = 0;

void setup() {
  Serial.begin(115200);

  servo.attach(ServoPin);

  Serial.println("Servo setup complete.");
}

void loop() {
  for (angle = 0; angle <= 180; angle++) {
    servo.write(angle);
    Serial.print("Angle: ");
    Serial.println(angle);
    delay(40);
  }

  for (angle = 180; angle >= 0; angle--) {
    servo.write(angle);
    Serial.print("Angle: ");
    Serial.println(angle);
    delay(40);
  }
}
