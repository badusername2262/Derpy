cmake_minimum_required(VERSION 3.27)
project(Derpy VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(Engine)
add_subdirectory(Game)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT "Engine")