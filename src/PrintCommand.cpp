#include "PrintCommand.hpp"
#include <LEDSubsystem.hpp>
#include <SafeSerial.hpp>

PrintCommand::PrintCommand(int durationMs) : duration(durationMs) {}

void PrintCommand::Initialize() {
    startTime = millis();
}

void PrintCommand::Execute() {
    SafeSerial::println("Hello, ESP32!");
    vTaskDelay(pdMS_TO_TICKS(500));
}

bool PrintCommand::IsFinished() {
    return millis() - startTime >= duration;
}

void PrintCommand::End() {
    SafeSerial::println("PrintCommand Finished.");
}