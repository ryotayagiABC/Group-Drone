## Multiple Temperature Sensors with MLX90614 and DS18B20

This Arduino sketch demonstrates how to read temperature values from multiple MLX90614 infrared thermometers and DS18B20 digital temperature sensors. The MLX90614 sensors communicate over I2C, while the DS18B20 sensors use the OneWire protocol.

### Prerequisites

- Arduino board
- Multiple MLX90614 infrared thermometers
- Multiple DS18B20 digital temperature sensors
- Wire library
- SparkFunMLX90614 library
- OneWire library
- DallasTemperature library

### Wiring

#### MLX90614
Connect the SDA and SCL pins of the MLX90614 sensors to the corresponding SDA and SCL pins on the Arduino board.

#### DS18B20
Connect each DS18B20 sensor's data wire to the corresponding digital pins on the Arduino board. The pin numbers are defined in the `ONE_WIRE_BUS` array.

### Code Explanation

- Include the necessary libraries: Wire, SparkFunMLX90614, OneWire, and DallasTemperature.
- Define the number of MLX90614 sensors and DS18B20 sensors.
- Create a class `SensorMLX90614` to handle the MLX90614 sensors. It initializes the sensors and reads the temperature values.
- Create a class `SensorDS18B20` to handle the DS18B20 sensors. It initializes the sensors and reads the temperature values.
- Create instances of the `SensorMLX90614` and `SensorDS18B20` classes.
- Define the addresses of the MLX90614 sensors.
- In the `setup()` function:
  - Initialize the Wire communication for the MLX90614 sensors.
  - Begin the MLX90614 sensors.
  - Start serial communication for debugging purposes.
  - Begin the DS18B20 sensors.
- In the `loop()` function:
  - Set the desired interval for temperature readings.
  - Read and print the temperature values from the MLX90614 sensors.
  - Read and print the temperature values from the DS18B20 sensors.

### Additional Information

Make sure to adjust the addresses and pin numbers according to your sensor connections.