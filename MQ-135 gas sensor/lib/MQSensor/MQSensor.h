#include <Arduino.h>

class MQSensor
{
private:

    int _analogPin;
    
    int _normalizedMinimalValue;

    const int ACCURANCY = 5;

    const int ACCURANCY_SHIFT = 5;

    const size_t _checkIterationCount = 120;

    void setDungeourLevel(const int &valueFromMq)
    {
        for (size_t i = 1; i <= 5; i++)
        {
            digitalWrite(i + 1, valueFromMq - _normalizedMinimalValue >= (i * ACCURANCY));
        }
    }

    void setCalibrLED(const bool &state)
    {
        digitalWrite(5, state);
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

    int getNorm()
    {
        return _normalizedMinimalValue;
    }

    int getSensorLevel()
    {
        return analogRead(_analogPin);
    }

    void calibrateSensor()
    {
        setCalibrLED(true);

        int sensorSum = 0;

        for (size_t i = 0; i < _checkIterationCount; i++)
        {
            delay(1000);
            sensorSum += getSensorLevel();
        }

        _normalizedMinimalValue = sensorSum / _checkIterationCount - ACCURANCY_SHIFT;

        setCalibrLED(false);
    }
};