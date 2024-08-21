#define pin 1
#define High 1
#define Low 0

void setup() {
  pinMode(pin, OUTPUT);
}

void loop() {
  digitalWrite(pin, High);
  delay(500);
  digitalWrite(pin, Low);
  delay(500);
}
