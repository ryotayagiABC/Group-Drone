## DS18B20.ino

This is a simple Arduino sketch that reads temperature values from a Dallas Temperature sensor and displays them on the serial monitor. It is based on the Dallas Temperature Library example.

### Prerequisites

- Arduino board
- Dallas Temperature sensor
- OneWire library
- DallasTemperature library

### Wiring

Connect the data wire of the Dallas Temperature sensor to digital pin 4 of the Arduino board.

### Code Explanation

- Include the necessary libraries: OneWire and DallasTemperature.
- Define the digital pin to which the data wire of the sensor is connected (pin 4 in this case).
- Create an instance of the OneWire class, passing the digital pin as a parameter.
- Create an instance of the DallasTemperature class, passing the OneWire instance as a parameter.
- In the `setup()` function:
  - Start serial communication for debugging purposes.
  - Initialize the DallasTemperature library.
- In the `loop()` function:
  - Call `sensors.requestTemperatures()` to request temperature readings from all devices on the bus.
  - Print the temperature in Celsius using `sensors.getTempCByIndex(0)`, where 0 refers to the first device on the bus.
  - Print the temperature in Fahrenheit using `sensors.getTempFByIndex(0)`.
  - Delay for 1 second before repeating the loop.

### Additional Information

For complete project details, visit [https://randomnerdtutorials.com](https://randomnerdtutorials.com).


## DS18B20_for_five.ino

This Arduino sketch demonstrates how to read temperature values from multiple Dallas Temperature sensors using threads. It utilizes the StaticThreadController, Thread, OneWire, and DallasTemperature libraries.

### Prerequisites

- Arduino board
- Multiple Dallas Temperature sensors
- StaticThreadController library
- Thread library
- OneWire library
- DallasTemperature library

### Wiring

Connect each data wire of the Dallas Temperature sensors to the corresponding digital pins on the Arduino board. The number of sensors and their corresponding pins are defined in the `ONE_WIRE_BUS` array.

### Code Explanation

- Include the necessary libraries: StaticThreadController, Thread, OneWire, and DallasTemperature.
- Define an array `ONE_WIRE_BUS` that holds the digital pins to which the data wires of the sensors are connected.
- Create an array of OneWire instances and DallasTemperature instances, one for each sensor.
- Create an array `temperatureC` to store the temperature values for each sensor.
- Define a Thread object `temperatureThread`.
- Define variables to track the timing of temperature readings.
- Implement the `temperatureTask()` function, which is executed by the `temperatureThread`. It requests temperature readings from each sensor and stores them in the `temperatureC` array. If a sensor is not connected, it displays an error message.
- In the `setup()` function:
  - Start serial communication for debugging purposes.
  - Initialize each OneWire and DallasTemperature instance for each sensor, set the resolution, and begin communication.
  - Configure the `temperatureThread` to execute the `temperatureTask()`.
- In the `loop()` function:
  - Run the `temperatureThread`.

### Additional Information

Make sure to adjust the `ONE_WIRE_BUS` array to match the correct digital pin connections for your setup.

