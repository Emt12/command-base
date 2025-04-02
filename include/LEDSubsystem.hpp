#pragma once
#include <Subsystem.hpp>
#include <Arduino.h>

class LEDSubsystem : public Subsystem {
private:
    int pin;

public:
    LEDSubsystem(int pin);
    void SetState(bool state);
};