cmake_minimum_required(VERSION 3.27)
project(Game VERSION 0.0.1)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)
add_compile_definitions(DRPY_PLATFORM_WINDOWS)

if (CMAKE_GENERATOR MATCHES "Visual Studio 17 2022")
    if (CMAKE_BUILD_TYPE MATCHES "Debug")
        link_directories(../bin/debug)
    elseif(CMAKE_BUILD_TYPE MATCHES "Release")
        link_directories(../bin/release)
    endif()
else()
link_directories(../Engine/bin)
endif()

set(Extern_HEADERS ../Engine/src)

set(Game_SOURCES src/Application.cpp)

add_executable(Game ${Game_SOURCES})

target_link_libraries(Game Engine.dll)
target_precompile_headers(Game PRIVATE ../Engine/src/Pch.h)
target_include_directories(Game PRIVATE ${Extern_HEADERS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})