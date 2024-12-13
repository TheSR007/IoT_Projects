// Pin Definitions
#define TRAFFIC_SENSOR = A0;        // Traffic Flow Sensor (Potentiometer)
#define EMERGENCY_SENSOR = 2;        // Emergency Vehicle Sensor (Button 1)
#define PEDESTRIAN_SENSOR = 3;       // Pedestrian Crossing Sensor (Button 2)

#define GREEN_LED = 4;               // Normal Traffic LED
#define YELLOW_LED = 5;              // Heavy Traffic LED
#define BLUE_LED = 6;                // Emergency Vehicle LED
#define RED_LED = 7;                 // Pedestrian Crossing LED
#define BUZZER = 8;                 // Buzzer for critical cases

// Thresholds
#define TRAFFICTHRESHOLD = 500;     // Threshold for heavy traffic (adjustable)

// Function to reset all LEDs and BUZZER
void resetSystem() {
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(BLUE_LED, LOW);
  digitalWrite(RED_LED, LOW);
  digitalWrite(BUZZER, LOW);
}

void setup() {
  // Initialize LEDs and BUZZER as output
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  // Initialize sensors as input
  pinMode(EMERGENCY_SENSOR, INPUT_PULLUP);
  pinMode(PEDESTRIAN_SENSOR, INPUT_PULLUP);

  // Initialize Serial Monitor
  Serial.begin(9600);
}

void loop() {
  // Read sensor values
  int trafficFlow = analogRead(TRAFFIC_SENSOR);
  bool emergencyDetected = digitalRead(EMERGENCY_SENSOR);
  bool pedestrianDetected = digitalRead(PEDESTRIAN_SENSOR);

  // Reset all LEDs and BUZZER at the beginning of each cycle
  resetSystem();

  // Case Logic
  if (emergencyDetected && pedestrianDetected) {
    // Case 6: Emergency + Pedestrian
    digitalWrite(BLUE_LED, HIGH);
    digitalWrite(RED_LED, HIGH);
    Serial.println("Case 6: Emergency + Pedestrian detected.");
  } else if (emergencyDetected) {
    // Case 3 & 5: Emergency Vehicle Detected
    digitalWrite(BLUE_LED, HIGH);
    if(trafficFlow > TRAFFICTHRESHOLD){
      digitalWrite(BUZZER, HIGH);
      Serial.println("Case 5: Traffic + Emergency vehicle detected. Clear traffic!");
    } else
        Serial.println("Case 3: Emergency vehicle detected. Clear traffic!");
  } else if (pedestrianDetected) {
    // Case 4: Pedestrian Crossing
    digitalWrite(RED_LED, HIGH);
    Serial.println("Case 4: Pedestrian detected. Stop traffic.");
  } else if (trafficFlow > TRAFFICTHRESHOLD) {
    // Case 2: Heavy Traffic
    digitalWrite(YELLOW_LED, HIGH);
    Serial.println("Case 2: Heavy traffic detected.");
  } else {
    // Case 1: Normal Traffic
    digitalWrite(GREEN_LED, HIGH);
    Serial.println("Case 1: Normal traffic conditions.");
  }

  // Idle Mode (Case 7): If all sensors are inactive
  if (!emergencyDetected && !pedestrianDetected && trafficFlow < 100) {
    resetSystem();
    Serial.println("Case 7: Idle mode.");
  }

  // Delay for stability
  delay(500);
}
