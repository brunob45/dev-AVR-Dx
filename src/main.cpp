#include <Arduino.h>

void setup()
{
    interrupts();
    Serial.begin(115200);

    pinMode(PIN_PC7, INPUT_PULLUP);
    pinMode(PIN_PC6, OUTPUT);
}


void loop()
{
    static uint32_t last_update;

    const bool elapsed = (millis() - last_update) > 500;

    if (elapsed && digitalReadFast(PIN_PC7))
    {
        digitalWriteFast(PIN_PC6, CHANGE);
        last_update = millis();
    }
    if (Serial.available())
    {
        Serial.write(Serial.read());
    }
}