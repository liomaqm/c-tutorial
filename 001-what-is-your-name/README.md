# 001-what-is-your-name

This directory contains a simple C program that asks the user for their name and greets them.

## File Structure

- `main.c`: The main entry point of the program.
- `name.c`: Contains functions related to handling the user's name.
- `CMakeLists.txt`: CMake configuration file for building the program.

## How to Build and Run

### Using CMake

1. Open a terminal and navigate to this directory:
   ```sh
   cd 001-what-is-your-name
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
   ./what_is_your_name
   ```

### Direct Compilation (without CMake)

Alternatively, you can compile the program directly with gcc:

```sh
gcc main.c name.c -o what_is_your_name
./what_is_your_name
```

## License

See [LICENSE](../LICENSE) for license information.
