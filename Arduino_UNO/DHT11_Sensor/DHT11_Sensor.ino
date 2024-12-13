// DHT11 (Temperature and Humidity)
#include <EduIntro.h>  // install EduIntro library by Arduino LLC

#define DHT_PIN 2  // DHT11 connected to digital pin 2

DHT11 dht11(DHT_PIN);

void setup() {
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
  delay(3000);  // Wait for 3 seconds before taking another reading
}
