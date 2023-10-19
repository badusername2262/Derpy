cmake_minimum_required(VERSION 3.0.0)
project(Engine VERSION 0.0.1)

add_compile_definitions(DRPY_PLATFORM_WINDOWS DRPY_BUILD_DLL)

add_subdirectory(external/glfw)

set(LIBRARY_OUTPUT_PATH ../bin/x86_64/lib)

include_directories(external/GLFW/include/)

set(Engine_SOURCES src/Derpy/Engine.cpp)

add_library(Engine SHARED ${Engine_SOURCES})

target_link_libraries(Engine GLFW opengl32)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})