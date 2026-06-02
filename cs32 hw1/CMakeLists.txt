cmake_minimum_required(VERSION 3.10)
project(SetDataStructureProjects)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(test_set Set.cpp testSet.cpp)
add_executable(test_new_set newSet.cpp testnewSet.cpp)
add_executable(test_ssn_set Set.cpp SSNSet.cpp testSSNSet.cpp)
