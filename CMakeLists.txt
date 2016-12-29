# This configuration file outlines some of the ways Arduino CMake
# can be used. For a detailed explenation of all the options please
# reade README.rst.

cmake_minimum_required(VERSION 3.0)
set(CMAKE_TOOLCHAIN_FILE arduino-cmake/ArduinoToolchain.cmake) # Arduino Toolchain

Project(TestArduino C CXX)

set(ARDUINO_DEFAULT_BOARD uno) # Default Board ID, when not specified
set(ARDUINO_DEFAULT_PORT /dev/ttyACM0) # Default Port, when not specified
set(ARDUINO_DEFAULT_SERIAL picocom @SERIAL_PORT@)

#generate_arduino_firmware(test2 SKETCH "test2")
#generate_arduino_firmware(Elijah_alarm SKETCH "Elijah_alarm")

FILE(GLOB files RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "*")

FOREACH(infileName ${files})
    MESSAGE(STATUS "Process ino: ${infileName}")

    IF (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${infileName}/${infileName}.ino")
        MESSAGE(STATUS "Sketch: ${infileName}")
        generate_arduino_firmware(${infileName} SKETCH "${infileName}")
        add_custom_target(${infileName}.build DEPENDS ${infileName})
        add_custom_target(${infileName}.install DEPENDS ${infileName}-upload)
    ENDIF()
ENDFOREACH(infileName)

