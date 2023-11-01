cmake_minimum_required(VERSION 3.4...3.20)
project(Engine VERSION 0.0.1)

option(BUILD_WINDOWS "Build for Windows" ON)
option(BUILD_LINUX "Build for Linux"     OFF)

if(BUILD_WINDOWS)
    add_compile_definitions(DRPY_PLATFORM_WINDOWS DRPY_BUILD_DLL)
    set(GLFW_BUILD_WIN32 ON CACHE BOOL "Build for windows")
    add_compile_options(-fPIC)
endif()
if(BUILD_LINUX)
    add_compile_definitions(DRPY_PLATFORM_LINUX DRPY_BUILD_DLL)
    set(GLFW_BUILD_X11 ON CACHE BOOL "Build for X11")
    add_compile_options(-fPIC)
endif()

add_subdirectory(external/GLFW/)

set(LIBRARY_OUTPUT_PATH ../bin)

include_directories(external/GLFW/include/)

set(Engine_SOURCES src/Derpy/Engine.cpp src/Derpy/Window.cpp src//Derpy/logging/Logging.cpp)

add_library(Engine SHARED ${Engine_SOURCES})
target_precompile_headers(Engine PRIVATE src/Pch.h)

if(BUILD_WINDOWS)
target_link_libraries(Engine GLFW opengl32)
elseif(BUILD_LINUX)
target_link_libraries(Engine GLFW GL)
endif()