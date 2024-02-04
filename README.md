# The Sliding Puzzle
An implementation of Sliding Puzzle using FTXUI. This is a game you can play at any terminal.

<p align="center"><img src="https://github.com/MhmRhm/SlidingPuzzle/blob/main/doc/game_play.gif?raw=true" alt="Demo image"></img></p>

The contents of `./.devcontainer` are used to create a cross-platform containerized development environment using the provided `Dockerfile`. If you are using vscode, look into *Remote Development* extension.

- Read the `./INSTALL` and provide dependencies.
- In-source builds are not allowed and disabled(see `./cmake/NoInSourceBuilds.cmake`). Use as follows:

```bash
cmake -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_C_COMPILER=clang -B ../build-llvm-debug -S .
cmake -DCMAKE_CXX_COMPILER=g++ -DCMAKE_C_COMPILER=gcc -B ../build-gcc-debug -S .
cmake --build ../build-gcc-debug
cmake --build ../build-llvm-debug
```
- You can also use presets provided with the project in `CMakePresets.json`. Your [IDE](https://learn.microsoft.com/en-us/cpp/build/cmake-presets-vs?view=msvc-170#configure) should support that or:

```bash
cmake --preset <configurePreset>
```
