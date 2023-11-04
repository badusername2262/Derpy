cmake_minimum_required(VERSION 3.4...3.20)
project(Game VERSION 0.0.1)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    add_compile_definitions(DRPY_PLATFORM_WINDOWS)
    set(EngineLibraryName "Engine.dll")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    add_compile_definitions(DRPY_PLATFORM_LINUX)
    set(EngineLibraryName "Engine.so")
endif()

include_directories(../Engine/external/GLFW/include/)

set(Extern_HEADERS ../Engine/src/)

set(Game_SOURCES src/Application.cpp)

add_executable(Game ${Game_SOURCES})

link_directories(../Engine/bin/)

find_library(ENGINE_LIBRARY Engine HINTS ${CMAKE_SOURCE_DIR}/../Engine/bin)

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
target_link_libraries(Game PRIVATE ${ENGINE_LIBRARY})
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
target_link_libraries(Game PRIVATE ${ENGINE_LIBRARY})
endif()

target_precompile_headers(Game PRIVATE ../Engine/src/Pch.h)
target_include_directories(Game PRIVATE ${Extern_HEADERS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
