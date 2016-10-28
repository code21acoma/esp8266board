//
//-----------------------------------------------------------
#include <OneWire.h> //2016/10 - bylo nutno stáhnout novou verzi:
//https://github.com/PaulStoffregen/OneWire
#include <DallasTemperature.h> // knihovna pro sensor DS18B20
#include <Wire.h> //pro i2c a oled
#include "oeESP.h"

// ------ declaration DS18B20
#define ONE_WIRE_BUS 0
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
//------ /declar

int interval=2;
//------------------------------------------------------------
float minC = 199;
float maxC = -99;
float minC1 = 199;
float maxC1 = -99;
float minC2 = 199;
float maxC2 = -99;
float celsius;

unsigned long previousMillis = 0;

void setup() {
  Serial.begin(115200);
  Serial.println("Dallas test"); 
  sensors.begin();  // ----- DS18B20
  delay(1000); 
  ledRGB(); 
}

void loop() {
  blinkBlu();
  
  unsigned long currentMillis = millis();
  
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    // ------ DS18B20
    sensors.requestTemperatures(); // Send the command to get temperatures
    celsius = sensors.getTempCByIndex(0);

    Serial.println(celsius);
    if (int(celsius)>25) 
    {
    ledRed(); 
     delay(500);  
     } 
   }
}
