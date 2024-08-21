void setup()
{

pinMode(2, OUTPUT);
Serial.begin(9600);

}


void loop()
{
  if(analogRead(15)>15){
    if(digitalRead(2))  
      digitalWrite(2,LOW);
    else if(!digitalRead(2))
      digitalWrite(2,HIGH);
  }
  Serial.println(analogRead(15));
  Serial.println("------------------");
  delay(1000);

}