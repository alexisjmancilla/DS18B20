// 18 Jul 2023 - Alexis Mancilla - ITEDA
// Adquisicion de Temperatura Sensores ds18b20 y muestra de datos por puerto serie con valores separados por comas
// Probado con 3 sensores conectados con una resistencia pull-up de 4K7. 
// Probado con un arduino Mega 2560, con el bus de datos conectado al pin digital 2

#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2 // Pin del bus OneWire
#define SENS 3 // Cantidad de sensores
#define TIMESAMPLE 1000 //tiempo entre adquisición de datos (en ms)

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

DeviceAddress sensorAddresses[SENS] = {
{0x28, 0xAA, 0x70, 0xB6, 0x47, 0x14, 0x1, 0xBA},
{0x28, 0xAA, 0x5D, 0xED, 0x47, 0x14, 0x1, 0xE2},
{0x28, 0xAA, 0x47, 0xBE, 0x47, 0x14, 0x1, 0x73},
  // direcciones de los sensores
};

void setup() {
  Serial.begin(9600);
  sensors.begin();
}

void loop() {
  sensors.requestTemperatures();
  for (uint8_t i = 0; i < SENS; i++) {
    if (i > 0) {
      Serial.print(",");
    }
    float tempC = sensors.getTempC(sensorAddresses[i]);
    Serial.print(tempC);
  }

  Serial.println();
  delay(TIMESAMPLE); 
}
