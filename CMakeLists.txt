#Dependencies
#GTK3
#LEAP MOTION DRIVER & SDK
#xdotool

cmake_minimum_required(VERSION 3.12)

project(LeapGestures)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall")

add_executable(leapObject main.cpp gestures.h gestures.cpp listener.h listener.cpp debug.cpp interface.h interface.cpp state.h state.cpp window.cpp window.h inter.cpp inter.h)
find_library(LEAP_LIBRARY NAMES libLeap.so)

#GTK3 Directives
find_package(PkgConfig REQUIRED)
find_package( Threads )
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
INCLUDE_DIRECTORIES(${GTK3_INCLUDE_DIRS})
LINK_DIRECTORIES(${GTK3_LIBRARY_DIRS})
# Add other flags to the compiler
ADD_DEFINITIONS(${GTK3_CFLAGS_OTHER})


#GTKMM
pkg_check_modules(GTKMM gtkmm-3.0)
link_directories(${GTKMM_LIBRARY_DIRS})
include_directories(${GTKMM_INCLUDE_DIRS})


target_link_libraries(leapObject ${LEAP_LIBRARY} ${GTK3_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT} ${GTKMM_LIBRARIES})
