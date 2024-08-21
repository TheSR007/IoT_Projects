TaskHandle_t FirstTask;
TaskHandle_t SecondTask;
void Task1( void * pvParameters ){
  while (true){
    Serial.println("First Task Running  on Core: ");
    Serial.println((xPortGetCoreID()));
    delay(2500);

  }
}

void Task2( void * pvParameters ){
  while (true){
    Serial.println("Second Task Running  on Core: ");
    Serial.println((xPortGetCoreID()));
    Serial.println("--------------------------------");
    delay(3000);
    
  }
}

void setup()
{
Serial.begin(9600);

  delay(3000);    //delay to open the serial monitor
  Serial.println("Starting");
  //create a task that will be executed in the Task1() function, with priority 1 and executed on core 0
  xTaskCreatePinnedToCore(
     Task1,    //Task function.
     "FirstTask", //name of task
     10000, //Stack size of task
     NULL, //parameter of the task
     1, //priority of the task
     &FirstTask, //Task handle to keep track of created task
     0); //pin task to core 0
  //create a task that will be executed in the Task2() function, with priority 1 and executed on core 1
  xTaskCreatePinnedToCore(
     Task2,    //Task function.
     "SecondTask", //name of task
     10000, //Stack size of task
     NULL, //parameter of the task
     1, //priority of the task
     &SecondTask, //Task handle to keep track of created task
     1); //pin task to core 1

}


void loop()
{


}