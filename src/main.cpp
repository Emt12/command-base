#include <Arduino.h>
#include <Subsystem.hpp>
#include <LEDSubsystem.hpp>
#include <BlinkCommand.hpp>
#include <PrintCommand.hpp>
#include <SafeSerial.hpp>
#include <Scheduler.hpp>

Scheduler scheduler;
LEDSubsystem ledSubsystem(2);
BlinkCommand blinkCommand(&ledSubsystem, 1000);
PrintCommand printCommand(5000);

void checkMemory() {
    Serial.printf("Free heap: %d\n", esp_get_free_heap_size());
    Serial.printf("Min free heap: %d\n", esp_get_minimum_free_heap_size());
}

void setup() {
    Serial.begin(115200);
    delay(1000);
    Serial.flush();
    Serial.clearWriteError();
    //delay(5000);
    SafeSerial::begin();
    scheduler.Schedule(&blinkCommand, 1);
    scheduler.Schedule(&printCommand, 1, 2048);
    //checkMemory();
}

void loop() {
    vTaskDelay(pdMS_TO_TICKS(1000));
}