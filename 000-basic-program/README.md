# 000-basic-program

This directory contains a simple C program demonstrating the basics of C programming.

## File Structure

- `basic_program.c`: The main source file containing the basic C program.
- `CMakeLists.txt`: CMake configuration file for building the program.

## How to Build and Run

### Using CMake

1. Open a terminal and navigate to this directory:
   ```sh
   cd 000-basic-program
   ```
2. Create a build directory and navigate into it:
   ```sh
   mkdir build && cd build
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
   ./basic_program
   ```

### Direct Compilation (without CMake)

Alternatively, you can compile the program directly with gcc:

```sh
gcc basic_program.c -o basic_program
./basic_program
```

## License

See [LICENSE](../LICENSE) for license information.
