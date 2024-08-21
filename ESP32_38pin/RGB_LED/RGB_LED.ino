void setup()
{
pinMode(15, OUTPUT);
pinMode(5, OUTPUT);
pinMode(16, OUTPUT);
}


void loop()
{
    //color cycle
    digitalWrite(5,HIGH);
    digitalWrite(15,LOW);
    digitalWrite(16,LOW);
    delay(2000);
    digitalWrite(5,LOW);
    digitalWrite(15,HIGH);
    digitalWrite(16,LOW);
    delay(2000);
    digitalWrite(5,LOW);
    digitalWrite(15,LOW);
    digitalWrite(16,HIGH);
    delay(2000);
    digitalWrite(5,HIGH);
    digitalWrite(15,HIGH);
    digitalWrite(16,LOW);
    delay(2000);
    digitalWrite(5,LOW);
    digitalWrite(15,HIGH);
    digitalWrite(16,HIGH);
    delay(2000);
    digitalWrite(5,HIGH);
    digitalWrite(15,LOW);
    digitalWrite(16,HIGH);
    delay(2000);
    digitalWrite(5,HIGH);
    digitalWrite(15,HIGH);
    digitalWrite(16,HIGH);
    delay(2000);
    digitalWrite(5,LOW);
    digitalWrite(15,LOW);
    digitalWrite(16,LOW);
    delay(1000);

}