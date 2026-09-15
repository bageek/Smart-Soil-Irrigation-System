/*
 * Smart Soil Irrigation System
 * 
 * Description: A cyber-physical IoT prototype designed for precision agriculture.
 * The system reads analog data from a soil moisture sensor, processes the 
 * environmental conditions through an edge-threshold algorithm, and dynamically 
 * triggers a 5V relay to actuate a DC water pump.
 * 
 * Hardware: Arduino Uno, Capacitive Soil Moisture Sensor, 5V Relay Module, DC Water Pump.
 */

// Define Hardware Pins
const int moistureSensorPin = A0;  // Analog pin for soil moisture sensor
const int relayPin = 8;            // Digital pin for the 5V relay module

// Define Thresholds (Calibrated for standard soil conditions)
// Note: Analog read returns 0-1023. Lower values typically mean wetter soil depending on sensor type.
const int dryThreshold = 700;      // Value above which the soil is considered dry
const int wetThreshold = 400;      // Value below which the soil is considered adequately watered

void setup() {
  // Initialize serial communication for debugging and data logging
  Serial.begin(9600);
  
  // Configure pins
  pinMode(moistureSensorPin, INPUT);
  pinMode(relayPin, OUTPUT);
  
  // Ensure the pump is off at startup (Active LOW relay module assumption)
  digitalWrite(relayPin, HIGH); 
  
  Serial.println("System Initialized: Smart Soil Irrigation Active.");
}

void loop() {
  // 1. Read environmental data from the sensor
  int moistureLevel = analogRead(moistureSensorPin);
  
  // 2. Output telemetry data for monitoring
  Serial.print("Current Soil Moisture Reading: ");
  Serial.println(moistureLevel);

  // 3. Edge-threshold control logic
  if (moistureLevel > dryThreshold) {
    // Soil is dry -> Actuate Relay to turn ON the water pump
    digitalWrite(relayPin, LOW); 
    Serial.println("Status: SOIL DRY. Pump Activated.");
  } 
  else if (moistureLevel < wetThreshold) {
    // Soil is adequately wet -> De-actuate Relay to turn OFF the water pump
    digitalWrite(relayPin, HIGH);
    Serial.println("Status: OPTIMAL MOISTURE. Pump Deactivated.");
  }

  // 4. System delay to prevent hardware jitter and relay bouncing
  delay(2000); 
}
