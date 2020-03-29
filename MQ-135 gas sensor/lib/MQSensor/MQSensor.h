#include <Arduino.h>

class MQSensor
{
private:

    int _analogPin;
    
    int _normalizedMinimalValue;

    const int ACCURANCY = 5;

    const size_t _checkIterationCount = 60;

    void setDungeourLevel(const int &valueFromMq)
    {
        for (size_t i = 1; i <= 5; i++)
        {
            digitalWrite(i + 1, valueFromMq - _normalizedMinimalValue >= (i * ACCURANCY));
        }
    }

    void setAllLEDs(const bool &state)
    {
        for (size_t i = 1; i <= 5; i++)
        {
            digitalWrite(i + 1, state);
        }
    }

public:

    MQSensor(const int &analogPin):_analogPin(analogPin), _normalizedMinimalValue(20)
    {
        for (size_t pin = 2; pin <= 6; pin++)
        {
            pinMode(pin, OUTPUT);
        }
    }

    void displayDungeourLevel()
    {
        setDungeourLevel(getSensorLevel());
    }

    int getSensorLevel()
    {
        return analogRead(_analogPin);
    }

    void calibrateSensor()
    {
        int sensorSum = 0;

        for (size_t i = 0; i < _checkIterationCount; i++)
        {
            delay(300);
            setAllLEDs(i % 2);
            delay(300);
            sensorSum += getSensorLevel();
        }

        _normalizedMinimalValue = sensorSum / _checkIterationCount - ACCURANCY;

        setAllLEDs(false);
    }
};