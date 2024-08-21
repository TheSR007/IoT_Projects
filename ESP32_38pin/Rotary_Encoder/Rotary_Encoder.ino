#define Clk 5
#define Dt 15
#define Sw 16

int counter=0,currentStateClk,lastStateCLK,switchState;
String currentDIR = "";
unsigned long lastButtonPress = 0;

void setup()
{
Serial.begin(9600);
pinMode(Clk, INPUT);
pinMode(Dt, INPUT);
pinMode(Sw, INPUT_PULLUP);
lastStateCLK = digitalRead(Clk);
}


void loop()
{
    currentStateClk=digitalRead(Clk);
    if(currentStateClk != lastStateCLK && currentStateClk){   //changes to 1 and 0 continuously
      if (digitalRead(Dt)!=currentStateClk) { 
          counter--;
          currentDIR = "clockwise rotation";      //Dt is 0 while clockwise
      }
      else{
          counter++;
          currentDIR = "counterclockwise rotation";   //Dt is 1 wheb counterclockwise
      }
    Serial.println(digitalRead(Clk));
    Serial.println(digitalRead(Dt));
    Serial.println(digitalRead(Sw));
    Serial.print(currentDIR);
    Serial.print(" | ");
    Serial.println(counter);
    Serial.println("--------------------------------");
    
    }
    lastStateCLK = currentStateClk;
    switchState = digitalRead(Sw);
    if(!switchState){
      if(millis() - lastButtonPress >50)
        Serial.println("Button is pressed");
      lastButtonPress = millis();
    }
}