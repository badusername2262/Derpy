cmake_minimum_required(VERSION 3.4...3.20)
project(Game VERSION 0.0.1)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)

if(CMAKE_GENERATOR MATCHES "Visual Studio 17 2022")
    add_compile_definitions(DRPY_PLATFORM_WINDOWS)
    set(EngineLibraryName "Engine")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    add_compile_definitions(DRPY_PLATFORM_WINDOWS)
    set(EngineLibraryName "Engine.dll")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    add_compile_definitions(DRPY_PLATFORM_LINUX)
    set(EngineLibraryName "Engine.so")
endif()

set(Extern_HEADERS ../Engine/src/)

set(Game_SOURCES src/Application.cpp)

add_executable(Game ${Game_SOURCES})

if (CMAKE_GENERATOR MATCHES "Visual Studio 17 2022")
    if(CMAKE_BUILD_TYPE MATCHES "Debug")
        link_directories(../build/bin/Debug/)
    elseif(CMAKE_BUILD_TYPE MATCHES "Release")
        link_directories(../build/bin/Release/)
    endif()
else()
    link_directories(../Engine/bin/)
endif()

find_library(ENGINE_LIBRARY Engine HINTS ${CMAKE_SOURCE_DIR}/../Engine/bin)

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
target_link_libraries(Game PRIVATE ${ENGINE_LIBRARY})
elseif(CMAKE_GENERATOR MATCHES "Visual Studio 17 2022")
target_link_libraries(Game PUBLIC ${EngineLibraryName})
else()
target_link_libraries(Game PRIVATE ${ENGINE_LIBRARY})
endif()

target_precompile_headers(Game PRIVATE ../Engine/src/Pch.h)
target_include_directories(Game PRIVATE ${Extern_HEADERS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
