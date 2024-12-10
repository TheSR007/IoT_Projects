// Internal Led Blink
#define L 13
#define TX 1

void setup() {
  pinMode(L, OUTPUT);
  pinMode(TX, OUTPUT);
}

void loop() {
  for(int i = 150; i > 0; i -= 10){
    digitalWrite(TX, LOW);
    delay(i);
    digitalWrite(L, HIGH);
    delay(i);
    digitalWrite(TX, HIGH);
    delay(i);
    digitalWrite(L, LOW);
    delay(i);
  }
}