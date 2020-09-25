# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# Name of the project (will be the name of the plugin)
project(function-call)

file(GLOB SOURCE_FILES ${CMAKE_SOURCE_DIR}/../*.cpp)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_library( # Sets the name of the library.
			${PROJECT_NAME}

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
			 ${SOURCE_FILES}
			 )

include_directories(
	"~/sdk/nodejs-mobile/src"
	"~/sdk/nodejs-mobile/deps/v8/include"
	"~/sdk/nodejs-mobile/deps/uv/include"
	"~/sdk/nan"
	)

add_library( node
	SHARED
	IMPORTED )

# Gives our library file a .node extension without any "lib" prefix
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "" SUFFIX ".node")
