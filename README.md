# Derpy
**Welcome To the home of Derpy Game Engine.**

While name Derpy is not an acronym, it is a fitting name.\
The reason for this is that the deffintion of Derpy is "foolish or stupid".\
So welcome to my stupid Game Engine!!

Unfortunately there isn't much here at the moment. \
This project is still new and is being maintained (just slowly).

Thanks,\
Badusername2262.
# How To Clone Derpy
To clone Derpy and it's Git Modules all need is the command line version of git.\
And to use this command in the terminal
```
git clone --recurse-submodules https://github.com/badusername2262/DERPY
```

# Visual Studio Cmake
To compile the project in Visual Studio you have to use cmake in command line from the Derpy Directory.

>**Only tested in visual studio 17 2022**

To build Derpy in Debug you would use this command. what the command does is generates the .sln file then compiles it in **x64 Debug mode**
```
cmake -DCMAKE_BUILD_TYPE=Debug -G"Visual Studio 17 2022" && cmake --build . --target ALL_BUILD --config Debug
```

To build Derpy in Release you would use this command. what the command does is generates the .sln file then compiles it in **x64 Release mode**
```
cmake -DCMAKE_BUILD_TYPE=Release -G"Visual Studio 17 2022" && cmake --build . --target ALL_BUILD --config Release
```
# Visual Studio Code
To use in visual Studio Code you will need a C++ compiler.\
you can get a C++ comiler from **msys2.org**.
>**This way of compilation has only been tested with msys2 MinGW64 GCC 13.\
You also will need to have the C/C++ Extension Pack installed to compile without errors**

Once you have a C++ compiler of your choice installed you will need to open the **Derpy.code-workspace** file in Visual Studio Code.

First you have to build the **Engine** project first, after it has finished compiling you can then build the **Game** project.\
After you have compiled both you will need to move the .dll file from **Derpy/Engine/bin/Engine.dll** and move it to **Derpy/Game/bin** where the Game.exe is located.\
Once you have done that you should be able to run the Game.exe executable without any issues.