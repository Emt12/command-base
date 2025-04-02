#pragma once
#include "Command.hpp"
#include <Arduino.h>

class PrintCommand : public Command {
private:
    unsigned long startTime;
    int duration;

public:
    PrintCommand(int durationMs);
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
};