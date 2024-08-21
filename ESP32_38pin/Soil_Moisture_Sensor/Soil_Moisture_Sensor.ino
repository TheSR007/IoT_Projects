void setup()
{
pinMode(2, OUTPUT);

}


void loop()
{

    if (analogRead(15) < 2000) {
      digitalWrite(2,HIGH);

    } else {
      digitalWrite(2,LOW);

    }
    delay(1000);

}