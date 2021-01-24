#include <Arduino.h>

void setup()
{
    pinMode(PIN_PC7, INPUT_PULLUP);
    pinMode(PIN_PC6, OUTPUT);
}

void loop()
{
    if (digitalReadFast(PIN_PC7))
    {
        digitalWriteFast(PIN_PC6, CHANGE);
        delay(500);
    }
}