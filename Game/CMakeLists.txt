cmake_minimum_required(VERSION 3.27)
project(Game VERSION 0.0.1)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)
add_compile_definitions(DRPY_PLATFORM_WINDOWS)

link_directories(../Engine/bin)

set(Extern_HEADERS ../Engine/src)

set(Game_SOURCES src/Application.cpp)

add_executable(Game ${Game_SOURCES})

target_link_libraries(Game Engine.dll)
target_include_directories(Game PRIVATE ${Extern_HEADERS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})