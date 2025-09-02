# 010-raylib-sample

This directory contains a simple C program using [raylib](https://www.raylib.com/) to create a basic window.

## File Structure

- `sample.c`: The main source file demonstrating a basic raylib window.
- `CMakeLists.txt`: CMake configuration file for building the program.

## What we learn here

In this example, we are going to run the simplest raylib example that shows a window with some text.

## How to Build and Run

### Raylib setup

For a complete installation guide, refer to raylib official documentation.
On MacOS, this can be easily done with the `brew` command `brew install raylib`

### VSCode setup
You might need to update VSCode configuration to be able to detect where raylib is installed.

For instance, on MacOS with `brew`, the include file `raylib.h` will be installed in `/opt/homebrew/include` so
we can configure the C/C++ extension to search for the file in this path.

### Using CMake

1. Open a terminal and navigate to this directory:
   ```sh
   cd 010-raylib-sample
   ```
2. Create a build directory and navigate into it:
   ```sh
   mkdir .build && cd .build
   ```
3. Run CMake to configure the project:
   ```sh
   cmake ..
   ```
4. Build the program:
   ```sh
   make
   ```
5. Run the program:
   ```sh
   ./sample
   ```

### Direct Compilation (without CMake)

To be defined later.

## License

See [LICENSE](../LICENSE)