#define pin 2
void setup()
{
pinMode(pin, OUTPUT);//using pin 2 led

}

void loop()
{
    if (touchRead(T0) <= 30) //using the built in touch sensor 0 (pin P4)  (0-P4,2-P2,3-P15,4-P13,5-P12,6-P14,7-P27)
      digitalWrite(pin, LOW); //can also be used as High
    else {
      digitalWrite(pin, HIGH);
    }
}
