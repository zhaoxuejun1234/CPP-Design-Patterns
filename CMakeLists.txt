cmake_minimum_required(VERSION 3.25)
project(Design_Patterns)

set(CMAKE_CXX_STANDARD 14)
link_libraries(pthread)
add_executable(Design_Patterns   "19_Observer Pattern/main.cpp" "19_Observer Pattern/observer.h" "19_Observer Pattern/observer.cpp" "19_Observer Pattern/agents.cpp" "19_Observer Pattern/agents.h")
