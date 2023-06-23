# MLX90614ESF-DCC-000-TU Sensor Folder

This folder contains code related to the MLX90614ESF-DCC-000-TU sensor. The datasheet for this sensor can be downloaded 
[here](https://www.mouser.jp/ProductDetail/Melexis/MLX90614ESF-DCC-000-TU?qs=KuGPmAKtFKVaTr%252BZY1xRAw%3D%3D).

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


