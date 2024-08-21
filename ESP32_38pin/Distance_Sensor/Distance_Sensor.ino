#define trig 5    //pin number
#define eco 15    //pin number
int duration,distance;
void setup()
{
pinMode(trig, OUTPUT);
pinMode(eco, INPUT);
Serial.begin(9600);

}


void loop()
{

    digitalWrite(trig,LOW);
    delayMicroseconds(2);
    digitalWrite(trig,HIGH);
    delayMicroseconds(10);
    digitalWrite(trig,LOW);
    duration=pulseIn(eco,HIGH);
    distance=duration*0.034/2;
    Serial.print("Distance is ");
    Serial.print(distance);
    Serial.println(" M");
    delay(100);

}