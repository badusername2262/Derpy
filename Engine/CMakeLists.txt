cmake_minimum_required(VERSION 3.4...3.20)
project(Engine VERSION 0.0.1)

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    add_compile_definitions(DRPY_PLATFORM_WINDOWS DRPY_BUILD_DLL)
    set(GLFW_BUILD_WIN32 ON CACHE BOOL "Build for windows")
    add_compile_options(-fPIC)
endif()
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    add_compile_definitions(DRPY_PLATFORM_LINUX DRPY_BUILD_DLL)
    set(GLFW_BUILD_X11 ON CACHE BOOL "Build for X11")
    add_compile_options(-fPIC)
endif()

add_subdirectory(external/GLFW/)
add_subdirectory(external/glad/)

set(LIBRARY_OUTPUT_PATH ../bin)

include_directories(external/GLFW/include/ external/glad/include/)

set(Windows_Engine_SOURCES 
        src/Derpy/Engine.cpp
        src/Derpy/OSPlatform/WindowsWindow.cpp
        src/Derpy/Logging/Logging.cpp
        src/Derpy/Events/KeyboardInputMacros.cpp
        src/Derpy/Layers/Layer.cpp
        src/Derpy/Layers/LayerStack.cpp)

set(Linux_Engine_SOURCES 
        src/Derpy/Engine.cpp
        src/Derpy/OSPlatform/LinuxWindow.cpp
        src/Derpy/Logging/Logging.cpp
        src/Derpy/Events/KeyboardInputMacros.cpp
        src/Derpy/Layers/Layer.cpp
        src/Derpy/Layers/LayerStack.cpp)

if(GLFW_BUILD_WIN32)
add_library(Engine SHARED ${Windows_Engine_SOURCES})
elseif(GLFW_BUILD_X11)
add_library(Engine SHARED ${Linux_Engine_SOURCES})
endif()

target_precompile_headers(Engine PRIVATE src/Pch.h)

if(GLFW_BUILD_WIN32)
    target_link_libraries(Engine GLFW opengl32 GLAD)
elseif(GLFW_BUILD_X11)
    target_link_libraries(Engine GLFW GL GLAD)
endif()