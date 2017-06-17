#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_PIN 0

OneWire oneWire(ONE_WIRE_PIN);
DallasTemperature sensors(&oneWire);

void setup(void)
{
    // start serial port
    Serial.begin(9600);
    Serial.println("Dallas Temperature Demo");
    sensors.begin();
    Serial.print("Locating devices... Found ");
    Serial.print(sensors.getDeviceCount(), DEC);
    Serial.println(" devices.");
    // report parasite power requirements
    Serial.print("Parasite power is: ");
    if (sensors.isParasitePowerMode()) {
      Serial.println("ON");
    } else {
      Serial.println("OFF");
    }
}

void loop(void)
{
    Serial.print(" Requesting temperatures...");
    sensors.requestTemperatures();
    Serial.println("DONE");
    Serial.print("Temperature is: ");
    Serial.print(sensors.getTempCByIndex(0)); // There can by more then 1 sensors. 0 is the index of the first sensor
    delay(1000);
}

