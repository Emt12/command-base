#pragma once
#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/semphr.h>

class SafeSerial {
    static SemaphoreHandle_t mutex;
public:
    static void begin() {
        mutex = xSemaphoreCreateMutex();
    }
    
    template<typename T>
    static void println(T msg) {
        if (xSemaphoreTake(mutex, portMAX_DELAY) == pdTRUE) {
            Serial.println(msg);
            xSemaphoreGive(mutex);
        }
    }
};