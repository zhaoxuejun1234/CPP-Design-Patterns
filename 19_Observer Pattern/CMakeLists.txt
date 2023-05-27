cmake_minimum_required(VERSION 3.10)
project(Design_Patterns)

set(CMAKE_CXX_STANDARD 11)
link_libraries(pthread)
add_executable(Design_Patterns   "main.cpp" "observer.h" "observer.cpp" "agents.cpp" "agents.h")
