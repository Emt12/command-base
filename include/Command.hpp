#pragma once
#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

class Command {
protected:
    TaskHandle_t taskHandle = nullptr;
    bool isRunning = false;

    static void TaskRunner(void* pvParameters) {
        Command* cmd = static_cast<Command*>(pvParameters);
        cmd->Initialize();
        while (!cmd->IsFinished()) {
            cmd->Execute();
            vTaskDelay(pdMS_TO_TICKS(20));
        }
        cmd->End();
        cmd->isRunning = false;
        vTaskDelete(nullptr);
    }

public:
    virtual void Initialize() {}
    virtual void Execute() {}
    virtual bool IsFinished() { return false; }
    virtual void End() {}
    virtual ~Command() = default;

    bool Start(UBaseType_t priority = 1, uint16_t stackSize = 4096) {
        if (isRunning) return false;
        isRunning = (xTaskCreate(TaskRunner, "Cmd", stackSize, this, priority, &taskHandle) == pdPASS);
        return isRunning;
    }

    bool IsRunning() const { return isRunning; }
};