# LinearAlgebra
A C++ library for Linear Algebra functions, mostly for maths and computer graphics.
\
This project uses CMake to build the library (static). Ensure that you are using a CMake version newer than 3.10.
To check the version, run this
```bash
cmake --version
```
You should see something like:
```bash
cmake version 3.16.3
```
You should also ensure that you are using a suitable compiler. E.g. gcc or clang
```bash
gcc --version
```
For me, it says:
```
gcc (Ubuntu 9.4.0-1ubuntu1~20.04.2) 9.4.0
Copyright (C) 2019 Free Software Foundation, Inc.
This is free software; see the source for copying conditions. There is  NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```
You should know the basics of how to use a CMakeLists.txt file. If not, check the documentation [here](https://cmake.org/cmake/help/v3.16/guide/tutorial/index.html#a-basic-starting-point-step-1). It's not very difficult to figure out what's going on if you just take a look at the file I have provided.
Then run the following in the root directory.
This will generate the build files. For the purpose of testing, I write code in the root in main.cpp and build it into an executable.
```bash
cmake -B build
cmake --build build
```
This will generate your executable in the build folder. Good luck!