#include <Arduino.h>

int normalizedMinimalValue = 20;
const int accuracy = 5;

void setDungeourLevel(int &valueFromMq)
{
  for (size_t i = 1; i <= 5; i++)
  {
    digitalWrite(i + 1, valueFromMq - normalizedMinimalValue >= (i * accuracy));
  }
}

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