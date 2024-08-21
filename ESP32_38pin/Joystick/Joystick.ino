void setup()
{
Serial.begin(9600);

}


void loop()
{

    if (analogRead(5) > 3000) {     //X in pin 5
      Serial.println("Top");

    }
    if (analogRead(5) < 1000) {
      Serial.println("Bottom");

    }
    if (analogRead(15) > 3000) {     //Y in pin 15
      Serial.println("Right");

    }
    if (analogRead(15) < 1000) {
      Serial.println("Left");

    }
    if (!analogRead(16)) {      //switch in pin 16
      Serial.println("Button Pressed");

    }
    Serial.println("--------------------------------------");
    delay(1000);

}