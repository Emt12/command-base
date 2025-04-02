#pragma once

class Subsystem {
public:
    virtual void Periodic() {}
    virtual ~Subsystem() = default;
};