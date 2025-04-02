#pragma once
#include <Command.hpp>
#include <vector>

class Scheduler {
private:
    std::vector<Command*> activeCommands;

public:
    bool Schedule(Command* command, UBaseType_t priority = 1, uint16_t stackSize = 4096) {
        if (command->Start(priority, stackSize)) {
            activeCommands.push_back(command);
            return true;
        }
        return false;
    }

    void CancelAll() {
        for (Command* cmd : activeCommands) {
            if (cmd->IsRunning()) {
                cmd->End();
            }
        }
        activeCommands.clear();
    }
};