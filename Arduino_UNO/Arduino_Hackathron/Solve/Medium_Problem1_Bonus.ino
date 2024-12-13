#include <EduIntro.h>  // install EduIntro library by Arduino LLC

#define DHT_PIN 2  // DHT11 connected to digital pin 2
#define RISE_SLOW_LED 3   // Rises Slowly LED
#define RISE_FAST_LED 4   // Rises Highly LED
#define DROP_SLOW_LED 5   // Drops Slowly LED
#define DROP_FAST_LED 6   // Drops Highly LED
#define CONST_LED 7   // Constant Temperature LED

DHT11 dht11(DHT_PIN);

float previousTemperature = 0.0;
unsigned long lastTime = 0;

void setup() {
  pinMode(RISE_SLOW_LED, OUTPUT);  // Rises Slowly LED
  pinMode(RISE_FAST_LED, OUTPUT);  // Rises Highly LED
  pinMode(DROP_SLOW_LED, OUTPUT);  // Drops Slowly LED
  pinMode(DROP_FAST_LED, OUTPUT);  // Drops Highly LED
  pinMode(CONST_LED, OUTPUT);      // Constant Temperature LED

  Serial.begin(9600);
}

void reset_leds(){
  // writing all low
  digitalWrite(RISE_SLOW_LED, LOW);
  digitalWrite(RISE_FAST_LED, LOW);
  digitalWrite(DROP_SLOW_LED, LOW);
  digitalWrite(DROP_FAST_LED, LOW);
  digitalWrite(CONST_LED, LOW);
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

  // Calculate temperature change rate
  float tempChange = temperature - previousTemperature;

  // Compare the rate of change and light up LEDs accordingly
  if (tempChange > 0.5) {
    // Highly rise (significant increase)
    reset_leds();
    digitalWrite(RISE_FAST_LED, HIGH);  // Highly rise
  } else if (tempChange > 0.2) {
    // Slow rise
    reset_leds();
    digitalWrite(RISE_SLOW_LED, HIGH);  // Slowly rise
  } else if (tempChange < -0.5) {
    // Highly drop (significant decrease)
    reset_leds();
    digitalWrite(DROP_FAST_LED, HIGH);  // Highly drop
  } else if (tempChange < -0.2) {
    // Slow drop
    reset_leds();
    digitalWrite(DROP_SLOW_LED, HIGH);  // Slowly drop
  } else {
    // Constant temperature
    reset_leds();
    digitalWrite(CONST_LED, HIGH);  // Constant temperature
  }

  previousTemperature = temperature;

  delay(100);
}
