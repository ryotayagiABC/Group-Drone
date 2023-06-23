# MLX90614ESF-DCC-000-TU Sensor Folder

This folder contains code related to the MLX90614ESF-DCC-000-TU sensor. The datasheet for this sensor can be downloaded 
[here](https://www.mouser.jp/ProductDetail/Melexis/MLX90614ESF-DCC-000-TU?qs=KuGPmAKtFKVaTr%252BZY1xRAw%3D%3D).

## How to Connect Sensor to Arduino

This README file provides instructions for setting up and using the raw script for the MLX90614 sensor module with an Arduino board. Follow the steps below to gather the necessary components and connect the sensor module to the Arduino. Additionally, you'll need to install the required libraries in the Arduino IDE.

### Components Needed

Before starting, make sure you have the following components:

- Arduino board (e.g., Arduino Uno, Arduino Nano)
- MLX90614 sensor module
- Breadboard and jumper wires
- Optional: I2C logic level converter (if needed)

### Connect the MLX90614 Sensor to the Arduino

To connect the MLX90614 sensor module to the Arduino board, follow these steps:

1. Connect the VCC pin of the sensor module to the 3.3V or 5V pin on the Arduino.
2. Connect the GND pin of the sensor module to the GND pin on the Arduino.
3. Connect the SDA pin of the sensor module to the SDA pin on the Arduino.
4. Connect the SCL pin of the sensor module to the SCL pin on the Arduino.

**Note:** If you're using a 5V Arduino board and the sensor module operates at 3.3V, you may need to use an I2C logic level converter to safely interface between the two devices.

### Install the Necessary Libraries

To install the required libraries for the MLX90614 sensor module, follow these steps:

1. Open the Arduino IDE on your computer.
2. Go to **Sketch** -> **Include Library** -> **Manage Libraries**.
3. In the Library Manager, search for **Adafruit MLX90614** and install the library.

Once you have installed the library, you can proceed with using the raw script to read data from the MLX90614 sensor module using your Arduino board.

**Note:** Make sure you have selected the correct board and port in the Arduino IDE before uploading the raw script to your Arduino board.

## Code Description

### check_address.ino
This Arduino program allows you to check the I2C address of the MLX90614ESF-DCC-000-TU sensor. It helps you identify the 
address at which the sensor is connected to the I2C bus.

### relocate_address.ino
This Arduino program enables you to change the I2C address of the MLX90614ESF-DCC-000-TU sensor. By running this code, you 
can modify the sensor's address to avoid conflicts with other devices on the I2C bus.

### thermo_for_one.ino
This Arduino program demonstrates how to interface and read data from a MLX90614ESF-DCC-000-TU sensor. 
It provides an example of reading temperature values from a sensor connected to an Arduino board.

### thermo_for_five.ino
This Arduino program demonstrates how to interface and read data from five MLX90614ESF-DCC-000-TU sensors simultaneously. 
It provides an example of reading temperature values from multiple sensors connected to an Arduino board.

Please refer to the respective Arduino files for more details on their implementation and usage.

For any additional information or support regarding the MLX90614ESF-DCC-000-TU sensor, please consult the datasheet or the 
manufacturer's documentation.

**Note:** The provided code files are intended for use with Arduino boards. Make sure you have the necessary hardware and 
development environment set up before using the code.

## Disclaimer
The code and information in this folder are provided as-is without any warranties or guarantees. It is your responsibility 
to review and understand the code before using it with your hardware. The authors and contributors of this folder shall 
not be held liable for any damages or losses arising from the use of this code.



