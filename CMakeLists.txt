cmake_minimum_required(VERSION 3.12)

project(ImGui-playground CXX C)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set (CMAKE_CXX_STANDARD 17)

if(WIN32)
	set(PYTHON_EXECUTABLE "python")
else()
	set(PYTHON_EXECUTABLE "python3")
endif()

if((NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/third_party/.bootstrap.json") OR ("${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.txt" IS_NEWER_THAN "${CMAKE_CURRENT_SOURCE_DIR}/third_party/.bootstrap.json"))
	execute_process(
		COMMAND ${PYTHON_EXECUTABLE} "bootstrap.py"
		WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
		RESULT_VARIABLE bootstrap_result
	)
	if (NOT (${bootstrap_result} EQUAL 0))
		message(FATAL_ERROR "Cannot run bootstrap.py")
	endif()
endif()

set(GLAD_SOURCES third_party/glad/src/gl.c)
if(WIN32)
	set(GLAD_SOURCES ${GLAD_SOURCES} third_party/glad/src/wgl.c)
endif()

set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "")
set(GLFW_BUILD_TESTS OFF CACHE BOOL "")
set(GLFW_BUILD_DOCS OFF CACHE BOOL "")
set(GLFW_INSTALL OFF CACHE BOOL "")
add_subdirectory(third_party/glfw)
include_directories(third_party/glfw/include)

add_library(glad ${GLAD_SOURCES})

add_subdirectory(layouts)