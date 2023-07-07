#include <StaticThreadController.h>
#include <Thread.h>
#include <ThreadController.h>
//#include <ArduinoThread>

#include <OneWire.h>
#include <DallasTemperature.h>

// Only need to change the port number
const int ONE_WIRE_BUS[] = {2, 3, 4, 5, 6};
const int NUM_SENSORS = sizeof(ONE_WIRE_BUS) / sizeof(ONE_WIRE_BUS[0]);

OneWire oneWire[NUM_SENSORS];
DallasTemperature sensors[NUM_SENSORS];
float temperatureC[NUM_SENSORS];

Thread temperatureThread;

unsigned long previousMillis = 0;
const unsigned long interval = 1000;  // 1 second interval

void temperatureTask() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    for (int i = 0; i < NUM_SENSORS; i++) {
      sensors[i].setWaitForConversion(false);
      sensors[i].requestTemperatures();
      temperatureC[i] = sensors[i].getTempCByIndex(0);

      if (temperatureC[i] != DEVICE_DISCONNECTED_C) {
        Serial.print(" ");
        Serial.print(temperatureC[i], 4);
        if (i == NUM_SENSORS - 1) {
          Serial.println(" C");
        } else {
          Serial.print(" C ||");
        }
      } else {
        Serial.print("Contact temp sensor ");
        Serial.print(i + 1);
        Serial.println(" is not connected.");
      }
    }
  }
}

void setup() {
  Serial.begin(9600);

  for (int i = 0; i < NUM_SENSORS; i++) {
    oneWire[i] = OneWire(ONE_WIRE_BUS[i]);
    sensors[i] = DallasTemperature(&oneWire[i]);
    sensors[i].begin();
    sensors[i].setResolution(12);
  }

  temperatureThread.onRun(temperatureTask);
  temperatureThread.setInterval(0);  // Run the thread as fast as possible
}

void loop() {
  temperatureThread.run();
}
