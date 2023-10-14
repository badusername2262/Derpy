cmake_minimum_required(VERSION 3.0.0)
project(Engine VERSION 0.0.1)

add_compile_definitions(DRPY_PLATFORM_WINDOWS DRPY_BUILD_DLL)

set(LIBRARY_OUTPUT_PATH ../bin/x86_64/lib)

set(Engine_SOURCES src/Derpy/Engine.cpp)

add_library(Engine SHARED ${Engine_SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})