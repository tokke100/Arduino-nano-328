#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define LED_green 2
#define LED_red 3
#define LED_yellow 4
#define ONE_WIRE_BUS 5

float tempC = 0;

OneWire wireBus(ONE_WIRE_BUS);
DallasTemperature sensor(&wireBus);

void setup() {

pinMode(LED_green, OUTPUT);
pinMode(LED_red, OUTPUT);
pinMode(LED_yellow, OUTPUT);

digitalWrite(LED_green, HIGH);
digitalWrite(LED_red, HIGH);
digitalWrite(LED_yellow, HIGH);

Serial.begin(9600);
sensor.begin();


}

void loop() {

Serial.println("Getting temperature...");
sensor.requestTemperatures();
Serial.print("Temperature:");
tempC = sensor.getTempCByIndex(0);
Serial.print(tempC);

if (tempC < 30) {
  digitalWrite(LED_green, HIGH);
  digitalWrite(LED_red, LOW);
  digitalWrite(LED_yellow, LOW);
}

if (tempC > 30 && tempC < 32) {
  digitalWrite(LED_green, LOW);
  digitalWrite(LED_red, LOW);
  digitalWrite(LED_yellow, HIGH);
}

if (tempC >32) {
  digitalWrite(LED_green, LOW);
  digitalWrite(LED_red, HIGH);
  digitalWrite(LED_yellow, LOW);
}

Serial.println("°C");
delay(1000);

}
