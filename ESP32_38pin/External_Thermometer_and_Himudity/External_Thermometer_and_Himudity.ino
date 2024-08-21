#include <DHT.h>

DHT dht(26, DHT11); //using pin 26 for data

void setup() {
  // put your setup code here, to run once:
  dht.begin();
  delay(2000);

  Serial.begin(9600);  //using serial 9600
}

void loop() {
  // put your main code here, to run repeatedly:
  float temp_C = dht.readTemperature();
  float temp_F = dht.readTemperature(true);
  float humidity = dht.readHumidity();
  Serial.print("Temp: ");
  Serial.print(temp_C);
  Serial.print(" °C / ");
  Serial.print(temp_F);
  Serial.println(" °F ");
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" % ");
  delay(3000);

}
