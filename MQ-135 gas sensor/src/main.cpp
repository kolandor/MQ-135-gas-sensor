#include <Arduino.h>

void setup()
{
  for (size_t pin = 2; pin <= 6; pin++)
  {
    pinMode(pin, OUTPUT);
  }

  Serial.begin(9600);

}

void loop()
{
  delay(600);
  int sensorValue = analogRead(A0);
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\n");
  setDungeourLevel(sensorValue);
}