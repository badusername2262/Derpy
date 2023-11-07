cmake_minimum_required(VERSION 3.4...3.20 FATAL_ERROR)
project(GLAD LANGUAGES C)

include_directories(include/)

set(LIBRARY_OUTPUT_PATH ../../../bin)

add_library(GLAD STATIC src/gl.c)