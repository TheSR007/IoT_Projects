// DHT11 (Temperature and Humidity)
#include <DHT.h>

#define DHT_PIN 2  // DHT11 connected to digital pin 2
#define DHT_TYPE DHT11  // Specify DHT type

DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();  // Initialize the DHT sensor
}

void loop() {
  float temperature = dht.readTemperature();  // Read temperature in Celsius
  float humidity = dht.readHumidity();  // Read humidity percentage

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
