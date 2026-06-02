cmake_minimum_required(VERSION 3.10)

project(rat_survival_cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(rat_survival
    Arena.cpp
    Game.cpp
    History.cpp
    Player.cpp
    Rat.cpp
    utilities.cpp
    main.cpp
)
