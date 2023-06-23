// This code is to check the address of MLX90614
#include <Wire.h>
#include <SparkFunMLX90614.h>

IRTherm sensor; // Create an IRTherm object

void setup() {
  Serial.begin(9600); // Initialize Serial communication
  Wire.begin(); // Initialize I2C bus
}

void loop() {
  byte address;
  for (address = 1; address <= 127; address++) {
    Wire.beginTransmission(address);
    if (Wire.endTransmission() == 0) {
      // If the sensor responds, print its address
      Serial.print("Sensor found at address: 0x");
      if (address < 16) {
        Serial.print("0");
      }
      Serial.println(address, HEX);
    }
  }
  delay(5000); // Wait for 5 seconds before scanning again
}