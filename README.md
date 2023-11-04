# Derpy

**Welcome to the home of Derpy Game Engine.**

While the name "Derpy" is not an acronym, it is a fitting name.\
The reason for this is that the definition of "Derpy" is "foolish or stupid."\
So, welcome to my foolish atempt at a Game Engine!!

Unfortunately, there isn't much here at the moment.\
This project is still new and is being maintained, albeit slowly.

## How To Clone Derpy

To clone Derpy and its Sub-Modules, all you need is the command line version of Git. Use this command in the terminal:

```shell
git clone --recurse-submodules https://github.com/badusername2262/DERPY
```

# ***Dependencies***
This Project Requires Vulkan sdk to be installed on the system. if you are using msys2 please download Vulkan in mingw64 terminal with this command:
```shell
pacman -S mingw-w64-x86_64-vulkan-devel
```

# ***Visual studio***
Regrettably, I have permanently removed the Visual Studio build system from CMake, as it wasn't compiling or functioning correctly. While it's no longer supported, I may explore the possibility of reintroducing it in the future

# ***Visual Studio Code***
To use Visual Studio Code, you will need a C++ compiler. You can get a C++ compiler from **msys2.org**.

>**This way of compilation has only been tested with msys2 MinGW64 GCC 13.\
You also need to have the C/C++ Extension Pack installed to compile without errors.**

Once you have a C++ compiler of your choice installed, open the **Derpy.code-workspace** file in Visual Studio Code.

First, you have to build the **Engine project**. After it has finished compiling, you can then build the **Game** project.\
After you have compiled both, move the .dll file from **Derpy/Engine/bin/Engine.dll** to **Derpy/Game/bin** where Game.exe is located.\
Once you have done that, you should be able to run the **Game.exe** executable without any issues.

# In-Source Build With Cmake For Windows
If you are planning to build in source, there are 3 steps at the moment.

The first step is to open a terminal or CMake-GUI in **Derpy/Engine**. Once inside, build the CMake file for your Generator of choice.

>You can do this by using **"CMake -G"** to see what Generators your version of CMake has.

>**This one is for Windows systems with Msys2 Mingw64, as Ninja comes pre-installed with it.**

```Cmake
cmake -B build && cd build && Ninja
```
This command should build **libGLFW.a, libEngine.dll, and libEngine.dll.a** in the **Derpy/Engine/bin** directory. **If you are building with Msys2 Mingw64.**

For the second step, you have to go from **Derpy/Engine/build** to **Derpy/Game**. Once there, you will have to do what you did in step one.

```Cmake
cmake -B build && cd build && Ninja
```

But this time, instead of building the libraries, it will build **Game.exe** in the **Derpy/Game/bin** directory.

That will conclude the first and second steps respectively. As for the third step, all you need to do is copy **libEngine.dll** from **Derpy/Engine/bin** to *Derpy/Game/bin**. Once you have done this, you should be able to run **Game.exe** located in **Derpy/Game/bin** directory without any errors, as long as it is running through the **Msys2 Terminal** unless you have added **c:/msys64/mingw64/bin** to your system environment variables.

# In-Source Build With CMake For Linux
If you are planning to build in source on Linux, there are only two steps to this.

The first step is to open a terminal or CMake-GUI in **Derpy/Engine**. Once inside, build the CMake file for your Generator of choice.

>You can do this by using **"CMake -G"** to see what Generators your version of CMake has.

>**This one is for Ubuntu systems with Gcc and G++ installed. Ubuntu should come with a version of Make installed.**

```Cmake
cmake -B build && cd build && Make
```
This command should build **libGLFW.a, libEngine.dll, and libEngine.dll.a** in the **Derpy/Engine/bin** directory. **If you are building with Msys2 Mingw64.**

For the second step, go from **Derpy/Engine/build** to **Derpy/Game**. Once there, do what you did in step one.

```Cmake
cmake -B build && cd build && Make
```
But this time, instead of building the libraries, it will build **Game** in the **Derpy/Game/bin** directory.

After you have completed these two steps, you should be able to run **Game**, even without the use of a terminal.

# End of README.md
Hey, if you have read all the way through this README.md file, thank you. I spent a long time writing this as this is my first proper attempt at making a Game Engine. If you have any feedback about this README file, please send it to Badusername2262@gmail.com. I would love to read your feedback.

Thanks,\
Badusername2262.
