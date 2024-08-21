#define pin 5 //change this if you change the pin
#define High_delay 5000 //5 sec in the high state
#define Low_delay 1000 //1 sec in the low state
void setup()
{
pinMode(pin, OUTPUT);

}


void loop()
{

    digitalWrite(pin,HIGH);
    delay(5000);
    digitalWrite(pin,LOW);
    delay(1000);

}