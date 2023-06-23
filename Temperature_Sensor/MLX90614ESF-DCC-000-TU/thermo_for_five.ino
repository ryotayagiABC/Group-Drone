#include <Wire.h> // I2C library, required for MLX90614
#include <SparkFunMLX90614.h> // Click here to get the library: http://librarymanager/All#Qwiic_IR_Thermometer by SparkFun
#define MLX90614_ADDRESS_1 0x5A
#define MLX90614_ADDRESS_2 0x5B
#define MLX90614_ADDRESS_3 0x5C
#define MLX90614_ADDRESS_4 0x5D
#define MLX90614_ADDRESS_5 0x5E
IRTherm therm1; // Create the first IRTherm object for the first sensor
IRTherm therm2; // Create the second IRTherm object for the second sensor
IRTherm therm3; // Create the third IRTherm object for the third sensor
IRTherm therm4; // Create the fourth IRTherm object for the fourth sensor
IRTherm therm5; // Create the fifth IRTherm object for the fifth sensor
void setup()
{
  Serial.begin(9600); // Initialize Serial to log output
  Wire.begin(); // Join I2C bus
  if (!therm1.begin(MLX90614_ADDRESS_1)) // Initialize the first thermal IR sensor
  {
    Serial.println("Qwiic IR thermometer at Address 1 did not acknowledge! Freezing!");
    while (1);
  }
  if (!therm2.begin(MLX90614_ADDRESS_2)) // Initialize the second thermal IR sensor
  {
    Serial.println("Qwiic IR thermometer at Address 2 did not acknowledge! Freezing!");
    while (1);
  }
  if (!therm3.begin(MLX90614_ADDRESS_3)) // Initialize the third thermal IR sensor
  {
    Serial.println("Qwiic IR thermometer at Address 3 did not acknowledge! Freezing!");
    while (1);
  }
  if (!therm4.begin(MLX90614_ADDRESS_4)) // Initialize the fourth thermal IR sensor
  {
    Serial.println("Qwiic IR thermometer at Address 4 did not acknowledge! Freezing!");
    while (1);
  }
  if (!therm5.begin(MLX90614_ADDRESS_5)) // Initialize the fifth thermal IR sensor
  {
    Serial.println("Qwiic IR thermometer at Address 5 did not acknowledge! Freezing!");
    while (1);
  }
  Serial.println("Qwiic IR Thermometers acknowledged.");
  therm1.setUnit(TEMP_C); // Set the units of the first sensor to Celsius
  therm2.setUnit(TEMP_C); // Set the units of the second sensor to Celsius
  therm3.setUnit(TEMP_C); // Set the units of the third sensor to Celsius
  therm4.setUnit(TEMP_C); // Set the units of the fourth sensor to Celsius
  therm5.setUnit(TEMP_C); // Set the units of the fifth sensor to Celsius
  pinMode(LED_BUILTIN, OUTPUT); // LED pin as output
}
void loop()
{
  digitalWrite(LED_BUILTIN, HIGH);
  // Read temperature from the first sensor
  if (therm1.read()) // On success, read() will return true
  {
    Serial.print("Sensor 1 - Object: " + String(therm1.object(), 2));
    Serial.println("C");
  //  Serial.print("Sensor 1 - Ambient: " + String(therm1.ambient(), 2));
   // Serial.println("C");
    Serial.println();
  }
  // Read temperature from the second sensor
  if (therm2.read()) // On success, read() will return true
  {
    Serial.print("Sensor 2 - Object: " + String(therm2.object(), 2));
    Serial.println("C");
    //Serial.print("Sensor 2 - Ambient: " + String(therm2.ambient(), 2));
    //Serial.println("C");
    Serial.println();
  }
  // Read temperature from the third sensor
  if (therm3.read()) // On success, read() will return true
  {
    Serial.print("Sensor 3 - Object: " + String(therm3.object(), 2));
    Serial.println("C");
    //Serial.print("Sensor 3 - Ambient: " + String(therm3.ambient(), 2));
    //Serial.println("C");
    Serial.println();
  }
  // Read temperature from the fourth sensor
  if (therm4.read()) // On success, read() will return true
  {
    Serial.print("Sensor 4 - Object: " + String(therm4.object(), 2));
    Serial.println("C");
    //Serial.print("Sensor 4 - Ambient: " + String(therm4.ambient(), 2));
    //Serial.println("C");
    Serial.println();
  }
  // Read temperature from the fifth sensor
  if (therm5.read()) // On success, read() will return true
  {
    Serial.print("Sensor 5 - Object: " + String(therm5.object(), 2));
    Serial.println("C");
    //Serial.print("Sensor 5 - Ambient: " + String(therm5.ambient(), 2));
    //Serial.println("C");
    Serial.println();
  }
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}