# 002-what-is-your-name-with-input

This directory contains a simple C program that asks the user for their name using standard input and then greets them.

## File Structure

- `input.c`: The main source file containing the program logic.
- `CMakeLists.txt`: CMake configuration file for building the program.

## How to Build and Run

### Using CMake

1. Open a terminal and navigate to this directory:
   ```sh
   cd 002-what-is-your-name-with-input
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
   ./what_is_your_name
   ```

### Direct Compilation (without CMake)

Alternatively, you can compile the program directly with gcc:

```sh
gcc input.c -o what_is_your_name
./what_is_your_name
```

## License

See [LICENSE](../LICENSE) for license