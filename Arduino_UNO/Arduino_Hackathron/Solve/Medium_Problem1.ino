// DHT11 (Temperature and Humidity)
#include <EduIntro.h>  // install EduIntro library by Arduino LLC

#define DHT 2  // DHT11 connected to digital pin 2
#define LOW_OUTPUT 3
#define HIGH_OUTPUT 4

DHT11 dht11(DHT);

void setup() {
  pinMode(LOW_OUTPUT, OUTPUT);
  pinMode(HIGH_OUTPUT, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  
  dht11.update();

  float temperature = dht11.readCelsius();  // Read temperature in Celsius
  float humidity = dht11.readHumidity();  // Read humidity percentage

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
  } else {
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print("°C, Humidity: ");
    Serial.print(humidity);
    Serial.println("%");
  }
  if(temperature <25){
    digitalWrite(LOW_OUTPUT, HIGH);
    digitalWrite(HIGH_OUTPUT, LOW);
  } else{
    digitalWrite(HIGH_OUTPUT, HIGH);
    digitalWrite(LOW_OUTPUT, LOW);
  }

  delay(300);  // Wait for 3 seconds before taking another reading
}
