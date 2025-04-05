// Pin Definitions
const int soilMoistureSensorPin = A0;  // Soil moisture sensor connected to Analog Pin A0
const int relayControlPin = 3;         // Relay module connected to Digital Pin 3

void setup() {
  // Initialize relay control pin as output
  pinMode(relayControlPin, OUTPUT);
  digitalWrite(relayControlPin, HIGH); // Keep the relay off initially (active LOW)

  // Initialize soil moisture sensor pin as input
  pinMode(soilMoistureSensorPin, INPUT);

  // Initialize serial monitor for debugging
  Serial.begin(9600);
  Serial.println("Smart Watering System Initialized");
}

void loop() {
  // Read the soil moisture sensor value
  int moistureValue = digitalRead(soilMoistureSensorPin);

  // Display moisture status on Serial Monitor
  Serial.print("Soil Moisture Status: ");
  Serial.println(moistureValue == LOW ? "Dry" : "Moist");

  // Corrected logic to turn the pump ON when soil is dry
  if (moistureValue == LOW) { // Soil is dry (LOW signal from sensor)
    digitalWrite(relayControlPin, LOW);  // Activate relay (pump ON)
    Serial.println("Pump ON: Watering the plants...");
  } else { // Soil is moist (HIGH signal from sensor)
    digitalWrite(relayControlPin, HIGH); // Deactivate relay (pump OFF)
    Serial.println("Pump OFF: Soil is moist.");
  }

  // Wait for a while before the next check
  delay(2000); // 2-second delay
}
