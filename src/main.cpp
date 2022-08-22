#include <Arduino.h>

void setup()
{
    Serial.begin(115200);

    pinMode(PIN_PC7, INPUT_PULLUP);
    pinMode(PIN_PC6, OUTPUT);
}

static uint32_t last_update;

void loop()
{
    if (millis() - last_update > 500)
    {
        last_update = millis();
        if (digitalReadFast(PIN_PC7))
        {
            digitalWriteFast(PIN_PC6, CHANGE);
        }
    }
    if (Serial.available())
    {
        Serial.write(Serial.read());
    }
}