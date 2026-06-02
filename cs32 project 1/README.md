# Rat Survival Game (C++)

Author: Siyan Tang  
Created: April 9, 2024

## Description

A console-based survival game implemented in C++ using object-oriented programming. The game simulates a player navigating a grid-based arena while avoiding rats and using poison pellets strategically.

## Features

- Grid-based arena simulation
- Player movement and survival logic
- Rat movement and poison interaction
- Turn-based game state updates
- History tracking for poisoned rat positions
- Safety-based movement recommendation

## Skills Demonstrated

- C++ programming
- Object-oriented design
- Dynamic memory management
- Game-state simulation
- Algorithmic decision making
- Modular code organization

## Build and Run

```bash
g++ -std=c++17 -Wall -Wextra -pedantic Arena.cpp Game.cpp History.cpp Player.cpp Rat.cpp utilities.cpp main.cpp -o rat_survival
./rat_survival
```

Or using CMake:

```bash
mkdir build
cd build
cmake ..
cmake --build .
./rat_survival
```
