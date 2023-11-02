cmake_minimum_required(VERSION 3.4...3.20)
project(Game VERSION 0.0.1)

option(BUILD_WINDOWS "Build for Windows" OFF)
option(BUILD_LINUX "Build for Linux"     ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)

if (BUILD_WINDOWS)
    add_compile_definitions(DRPY_PLATFORM_WINDOWS)
    set(EngineLibraryName "Engine.dll")
else()
    add_compile_definitions(DRPY_PLATFORM_LINUX)
    set(EngineLibraryName "Engine.so")
endif()

set(Extern_HEADERS ../Engine/src/)

set(Game_SOURCES src/Application.cpp)

add_executable(Game ${Game_SOURCES})

if (CMAKE_GENERATOR MATCHES "Visual Studio 17 2022")
    link_directories(../build/bin/)
else()
    link_directories(../Engine/bin)
endif()

find_library(ENGINE_LIBRARY Engine HINTS ${CMAKE_SOURCE_DIR}/../Engine/bin)

target_link_libraries(Game PRIVATE ${ENGINE_LIBRARY})



target_precompile_headers(Game PRIVATE ../Engine/src/Pch.h)
target_include_directories(Game PRIVATE ${Extern_HEADERS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
