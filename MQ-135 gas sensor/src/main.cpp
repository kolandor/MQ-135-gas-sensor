#include <Arduino.h>
#include "MQSensor.h"

MQSensor sensor(A0);

void setup()
{
  Serial.begin(9600);
  sensor.calibrateSensor();
}

void loop()
{
  delay(600);
  Serial.print("sensor = ");
  Serial.print(sensor.getSensorLevel());
  Serial.print("\n");
  sensor.displayDungeourLevel();
}