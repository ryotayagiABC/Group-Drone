#include <Wire.h>
#include <SparkFunMLX90614.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// MLX90614
const int NUM_SENSORS_MLX90614 = 5;


// DB18B20
const int ONE_WIRE_BUS[] = {2, 3, 4, 5, 6};
const int NUM_SENSORS_DB18B20 = sizeof(ONE_WIRE_BUS) / sizeof(ONE_WIRE_BUS[0]);


// MLX90614
class SensorMLX90614 {
public:
  SensorMLX90614(int* addresses, int count) : addresses(addresses), count(count) {}

  void begin() {
    for (int i = 0; i < count; i++) {
      if (!thermometers[i].begin(addresses[i])) {
        Serial.print("Qwiic IR thermometer at Address ");
        Serial.print(i + 1);
        Serial.println(" did not acknowledge! Freezing!");
        while (1);
      }
      thermometers[i].setUnit(TEMP_C);
    }
    Serial.println("Qwiic IR Thermometers acknowledged.");
  }

  void readTemperatures() {
    for (int i = 0; i < count; i++) {
      if (thermometers[i].read()) {
        Serial.print("Sensor MLX90614 ");
        Serial.print(i + 1);
        Serial.print(" - Object: ");
        Serial.print(thermometers[i].object(), 2);
        Serial.print(" - Ambient: ");
        Serial.print(thermometers[i].ambient(), 2);
        Serial.println(" C");
        Serial.println();
      }
    }
  }

  void printTemperatures(){
    for (int i = 0; i < count; i++) {
      if (thermometers[i].read()) {
        Serial.print(" ");
        Serial.print(thermometers[i].object(), 4);
        if (i == 4) {
          Serial.println(" C");
        } else {
          Serial.print(" C ||");
        }
      } else {
        Serial.print("Contact temp sensor");
        Serial.print(i+1);
        Serial.println(" is not connected.");
      }
    }
  }

private:
  int* addresses;
  int count;
  IRTherm thermometers[NUM_SENSORS_MLX90614];
};

// DB18B20
class SensorDS18B20 {
public:
  SensorDS18B20(int* pins, int count) : pins(pins), count(count) {}

  void begin() {
    for (int i = 0; i < count; i++) {
      oneWire[i] = OneWire(pins[i]);
      sensors[i] = DallasTemperature(&oneWire[i]);
      sensors[i].begin();
      sensors[i].setResolution(12);
    }
  }

  void readTemperatures() {
    for (int i = 0; i < count; i++) {
        sensors[i].setWaitForConversion(false);
        sensors[i].requestTemperatures();
        temperatureC[i] = sensors[i].getTempCByIndex(0);
        Serial.print("Sensor DS18B20 ");
        Serial.print(i + 1);
        Serial.print(" - Object: ");
        Serial.print(temperatureC[i]);
        Serial.println(" C");
        Serial.println();
    }
  }

  void printTemperatures(){
    for (int i = 0; i < count; i++) {
        sensors[i].setWaitForConversion(false);
        sensors[i].requestTemperatures();
        temperatureC[i] = sensors[i].getTempCByIndex(0);
      if (temperatureC[i] != DEVICE_DISCONNECTED_C) {
        Serial.print(" ");
        Serial.print(temperatureC[i], 4);
        if (i == 4) {
          Serial.println(" C");
        } else {
          Serial.print(" C ||");
        }
        // Serial.print("\n");
      } else {
        Serial.print("Contact temp sensor");
        Serial.print(i+1);
        Serial.println(" is not connected.");
      }
    }
  }


private:
  int* pins;
  int count;
  OneWire oneWire[NUM_SENSORS_DB18B20];
  DallasTemperature sensors[NUM_SENSORS_DB18B20];
  float temperatureC[NUM_SENSORS_DB18B20];
};

// DS18B20
SensorDS18B20 SensorDS18B20(ONE_WIRE_BUS, NUM_SENSORS_DB18B20);

// MLX90614
int mlx90614_addresses[] = {0x5A, 0x5B, 0x5C, 0x5D, 0x5E};
SensorMLX90614 sensorMLX90614(mlx90614_addresses, NUM_SENSORS_MLX90614);


void setup() {
  // MLX90614
  Wire.begin();
  sensorMLX90614.begin();
  // DS18B20
  Serial.begin(9600);
  SensorDS18B20.begin();
  pinMode(LED_BUILTIN, OUTPUT);
}



void loop() {
  static unsigned long previousMillis = 0;  // Variable to store the previous time
  //const unsigned long interval = 1000;      // Desired interval in milliseconds
  const unsigned long interval = 500;

  unsigned long currentMillis = millis();   // Get the current time

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;  // Update the previous time

    // Your code to execute every second
    Serial.print("MLX90614");
    digitalWrite(LED_BUILTIN, HIGH);
    //sensorMLX90614.readTemperatures();
    sensorMLX90614.printTemperatures();
    digitalWrite(LED_BUILTIN, LOW);

    Serial.print("DS18B20");
    //SensorDS18B20.readTemperatures();
    SensorDS18B20.printTemperatures();
  }
}





