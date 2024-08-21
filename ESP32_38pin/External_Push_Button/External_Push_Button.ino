void setup()
{
pinMode(15, INPUT);  //using pin 15 to read
pinMode(2, OUTPUT);  //using pin 2 to output(LED)
}


void loop()
{
    if(digitalRead(15))
    digitalWrite(2, HIGH);
    else if(!digitalRead(15))
    digitalWrite(2, LOW);
}