#pragma once
#include <Command.hpp>
#include <LEDSubsystem.hpp>

class BlinkCommand : public Command {
private:
    LEDSubsystem* led;
    unsigned long startTime;
    int duration;

public:
    BlinkCommand(LEDSubsystem* led, int durationMs);
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
};