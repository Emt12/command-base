#include "SafeSerial.hpp"
SemaphoreHandle_t SafeSerial::mutex = nullptr;