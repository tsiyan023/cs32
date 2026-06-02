cmake_minimum_required(VERSION 3.10)
project(BattleshipCpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(battleship
    Board.cpp
    Game.cpp
    Player.cpp
    main.cpp
)
