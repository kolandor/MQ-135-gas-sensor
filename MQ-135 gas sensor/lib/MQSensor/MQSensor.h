#include <Arduino.h>

class MQSensor
{
private:

    int _analogPin;
    
    int _normalizedMinimalValue;

    const int ACCURANCY = 5;

public:

    MQSensor(int &analogPin):_analogPin(analogPin), _normalizedMinimalValue(20)
    {
        for (size_t pin = 2; pin <= 6; pin++)
        {
            pinMode(pin, OUTPUT);
        }
    }

    void setDungeourLevel(int &valueFromMq)
    {
        for (size_t i = 1; i <= 5; i++)
        {
            digitalWrite(i + 1, valueFromMq - _normalizedMinimalValue >= (i * ACCURANCY));
        }
    }
};