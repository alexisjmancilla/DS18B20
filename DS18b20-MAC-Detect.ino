// 18 Jul 2023 - Alexis Mancilla - ITEDA
// Deteccion de Sensores ds18b20
// Probado con 3 sensores conectados con una resistencia pull-up de 4K7. 
// Probado con un arduino Mega 2560, con el bus de datos conectado al pin digital 2
#include <OneWire.h>

OneWire ourWire(2);                //Pin bus 2 OneWire

void setup(void) {
  Serial.begin(9600);
}

void loop(void) {
  byte addr[8];  
  Serial.println("MAC Address:");
  while (ourWire.search(addr)) 
  {  
  for( int i = 0; i < 8; i++) {
    Serial.print(" 0x");
    Serial.print(addr[i], HEX);
  }
  Serial.println();
}

Serial.println();
ourWire.reset_search();
delay(2000);
}
