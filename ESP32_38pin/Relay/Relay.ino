void setup()
{
pinMode(15, OUTPUT);

}


void loop()
{

    digitalWrite(15,HIGH);  //5 sec on
    delay(5000);
    digitalWrite(15,LOW);   //5 sec off
    delay(5000);

}