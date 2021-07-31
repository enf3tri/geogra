#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#define SensorPin A0 

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME280 bme;

float sensorValue = 0; 

String wifiName = "Geogra";                    
String wifiPassi = "I<3IBM";
String ip = "XXX.XXX.XXX.XXX";

int rxPin = 10;                                              
int txPin = 11;    

dht11 DHT11;

SoftwareSerial esp(rxPin, txPin);

void setup() {
  Serial.begin(9600);
  esp.begin(115200);
  if (!bme.begin(0x76)) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }
}

void loop() {

   for (int i = 0; i <= 100; i++) 
 { 
   sensorValue = sensorValue + analogRead(SensorPin); 
   delay(1); 
 } 
  Serial.print(bme.readTemperature());
  Serial.print(bme.readPressure() / 100.0F);
  Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
  Serial.print(bme.readHumidity());
  sensorValue = sensorValue/100.0; 
  Serial.println(sensorValue); 

  Serial.println();

  esp.println(veri.length()+2);
  if(esp.find(">")){                                          
    esp.print(veri);                                          
    Serial.println(veri);
    Serial.println("Data has been sent");
    delay(1000);
  }
  delay(1000);
}
