# Command Base Project

## Overview
The Command Base project is designed to demonstrate the use of a scheduler to manage tasks in an embedded environment. It utilizes the Arduino framework and is built for compatibility with ESP32 microcontrollers.

## Features
- Initializes serial communication for debugging and monitoring.
- Implements a scheduler to manage multiple commands.
- Monitors heap memory usage to ensure efficient resource management.

## File Structure
```
command-base
├── include          # Header files for the project
├── lib             # External libraries
├── src
│   └── main.cpp    # Main application logic
├── platformio.ini   # PlatformIO configuration file
└── README.md       # Project documentation
```

## Getting Started
1. Clone the repository or download the project files.
2. Open the project in your preferred IDE that supports PlatformIO.
3. Connect your ESP32 board to your computer.
4. Configure the `platformio.ini` file if necessary to match your board settings.
5. Upload the code to your ESP32 board.

## Usage
- The main application logic is contained in `src/main.cpp`.
- The `checkMemory` function can be uncommented to monitor heap usage during execution.
- The scheduler is set to execute the `blinkCommand` and `printCommand` at specified intervals.

## License
This project is licensed under the MIT License. See the LICENSE file for more details.