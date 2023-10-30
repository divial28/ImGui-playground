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