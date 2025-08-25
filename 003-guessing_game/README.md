# 003-guessing_game

This directory contains a simple C program for a guessing game.

## File Structure

- `base.c`: The main source file containing the guessing game logic.
- `CMakeLists.txt`: CMake configuration file for building the program.

## Tutorial

### what are we building?
The goal of the game is to ask the user to guess a number between 0 and 100.
For each guess, we tell the user if the number is smaller or bigger or if the user found the number.

This can be achieved by:
1. Create a random number
2. Initialize the number of remaining attempt
3. Ask the user to guess the number
4. Tell the user if they win and stop the program
5. If the user has lost, tell the user if the guessed number is bigger or smaller than the secret 
6. Reduce the number of remaining attempt by 1
7. [Optional] Tell the user the number of remaining attempts
8. Stop the program if the user cannot guess the number anymore

### What is new
This tutorial introduce:
- get user input (number) using `scanf()`
- create a random number using `rand()`
- use variable address `&` operator

About addresses:
So far, we have only use variable with type `int` or `char`.
When using the address of a variable, the type become `int*` or `char*` which means
 the value is not an integer or a character b but the address of an integer or 
 the address of a char.

This is mostly used when we want a function to modify the content of a variable.
More details in future tutorials.

### Challenge
Update the code to take as argument the number of attempts.
This can be done using `atoi()` provided by the library `<stdlib.h>`

For example, if the user run the program:
`./guessing_game`  : use the default number of attempt (5)
`./guessing_game 8`: change the number of attempt to 8 

## How to Build and Run

### Using CMake

1. Open a terminal and navigate to this directory:
   ```sh
   cd 003-guessing_game
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
   ./guessing_game
   ```

### Direct Compilation (without CMake)

Alternatively, you can compile the program directly with gcc:

```sh
gcc ../base.c -o guessing_game
./guessing_game
```

## License

See [LICENSE](../LICENSE) for