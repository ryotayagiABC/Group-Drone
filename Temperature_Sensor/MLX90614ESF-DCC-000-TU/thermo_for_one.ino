#include <Wire.h>
#include <Adafruit_MLX90614.h>

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

void setup() {
  mlx.begin();
  Serial.begin(9600);
}

void loop() {
  float ambientTemp = mlx.readAmbientTempC();
  float objectTemp = mlx.readObjectTempC();

  Serial.print("Ambient Temperature: ");
  Serial.print(ambientTemp);
  Serial.print(" °C\tObject Temperature: ");
  Serial.print(objectTemp);
  Serial.println(" °C");

  delay(1000); // Delay for 1 second before the next reading
}
