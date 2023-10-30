cmake_minimum_required(VERSION 3.12)

project(ImGui-layouts CXX C)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set (CMAKE_CXX_STANDARD 17)

include_directories(../third_party/imgui)
include_directories(../third_party/ImGuizmo)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE SRC_FILES LIST_DIRECTORIES false RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.c??)
file(GLOB_RECURSE HEADER_FILES LIST_DIRECTORIES false RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)

add_executable(${PROJECT_NAME} ${SRC_FILES} ${HEADER_FILES})

if(MSVC)
    add_definitions(-D_CONSOLE)
    set_property(TARGET ${PROJECT_NAME} PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")
endif()

target_link_libraries(${PROJECT_NAME} PUBLIC glad glfw)
