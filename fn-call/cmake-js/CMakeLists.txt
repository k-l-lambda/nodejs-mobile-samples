# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# Name of the project (will be the name of the plugin)
project(function-call)

SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/..)
include(${CMAKE_CURRENT_SOURCE_DIR}/../fn-call.cmake)

# Gives our library file a .node extension without any "lib" prefix
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "" SUFFIX ".node")
