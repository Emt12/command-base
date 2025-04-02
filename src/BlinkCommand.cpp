#include "BlinkCommand.hpp"
#include <SafeSerial.hpp>

BlinkCommand::BlinkCommand(LEDSubsystem* led, int durationMs)
    : led(led), duration(durationMs) {}

void BlinkCommand::Initialize() {
    startTime = millis();
}

void BlinkCommand::Execute() {
    //led->SetState((millis() / 500) % 2 == 0);
    SafeSerial::println("blink blink");
}

bool BlinkCommand::IsFinished() {
    return millis() - startTime >= duration;
}

void BlinkCommand::End() {
    led->SetState(false);
}