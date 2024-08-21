void setup()
{
Serial.begin(9600);

}


void loop()
{

    Serial.println((hallRead()));
    delay(1000);

}