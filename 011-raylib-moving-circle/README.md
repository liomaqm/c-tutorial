# 011-raylib-moving-circle

This directory contains a simple C program using [raylib](https://www.raylib.com/) to create a basic window
with a moving circle (with arrow keyboard keys).

## File Structure

- `main.c`: source file of first program
- `main.c`: source file of second program
- `CMakeLists.txt`: CMake configuration file for building the program.

## What we learn here

`main.c`
- Draw a circle
- get input from keys (pressed or pressing)
- Write text
- Colision with screen bounds

`main_auto.c`
- ball move on its own based on its speed

## How to Build and Run

### Raylib setup
See previous tutorial 010-raylib-sample

### Using CMake

1. Open a terminal and navigate to this directory:
   ```sh
   cd 011-raylib-moving-circle
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
   ./main
   ```

### Direct Compilation (without CMake)

To be defined later.

## License

See [LICENSE](../LICENSE)