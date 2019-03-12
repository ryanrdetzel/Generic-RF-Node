cmake_minimum_required(VERSION 3.0)
project(main)
set(SOURCE main.cpp)
add_executable(${PROJECT_NAME} ${SOURCE} node.cpp sensor.cpp sensor_ping.cpp sensor_int.cpp)