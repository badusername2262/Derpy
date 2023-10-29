cmake_minimum_required(VERSION 3.27)
project(Engine VERSION 0.0.1)

add_compile_definitions(DRPY_PLATFORM_WINDOWS DRPY_BUILD_DLL)

add_subdirectory(external/glfw)

set(LIBRARY_OUTPUT_PATH ../bin)

include_directories(external/GLFW/include/)

set(Engine_SOURCES src/Derpy/Engine.cpp src/Derpy/Window.cpp src//Derpy/logging/Logging.cpp)

add_library(Engine SHARED ${Engine_SOURCES})
target_precompile_headers(Engine PRIVATE src/Pch.h)

target_link_libraries(Engine GLFW opengl32)