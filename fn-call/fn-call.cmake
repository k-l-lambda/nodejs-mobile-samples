
file(GLOB SOURCE_FILES ${CMAKE_MODULE_PATH}/*.cpp)


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
