# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

project(functionCall)

SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/../../../fn-call)
include(${CMAKE_CURRENT_SOURCE_DIR}/../../../fn-call/fn-call.cmake)


add_library( node
	SHARED
	IMPORTED )

set_target_properties( # Specifies the target library.
		   node
		  # Specifies the parameter you want to define.
		  PROPERTIES IMPORTED_LOCATION
		  # Provides the path to the library you want to import.
			${CMAKE_SOURCE_DIR}/../app/libnode/bin/${ANDROID_ABI}/libnode.so )

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
						${PROJECT_NAME}

                       # Links the target library to the log library
                       # included in the NDK.
					   node ${log-lib} )
