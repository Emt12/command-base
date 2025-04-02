#include "LEDSubsystem.hpp"

LEDSubsystem::LEDSubsystem(int pin) : pin(pin) {
    pinMode(pin, OUTPUT);
}

void LEDSubsystem::SetState(bool state) {
    digitalWrite(pin, state ? HIGH : LOW);
}