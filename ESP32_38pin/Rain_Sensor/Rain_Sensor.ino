void setup()
{
pinMode(15, INPUT);
pinMode(2, OUTPUT);

}


void loop()
{

    if (!digitalRead(15)) 
      digitalWrite(2,HIGH);
    else
      digitalWrite(2,LOW);
    delay(1000);

}