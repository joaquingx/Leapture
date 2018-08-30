cmake_minimum_required(VERSION 3.12)

project(LeapGestures)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall")

add_executable(leapObject main.cpp gestures.h gestures.cpp listener.h listener.cpp debug.cpp)
find_library(LEAP_LIBRARY NAMES libLeap.so)

target_link_libraries(leapObject ${LEAP_LIBRARY})
