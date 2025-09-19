# Pointer Tutorial in C

This example demonstrates how pointers work in C, including how to swap values using pointers and how memory addresses are handled.

## Key Concepts

- **Pass-by-value vs Pass-by-reference:**  
  - `swap_bad(int a, int b)` shows that passing arguments by value does not affect the original variables.
  - `swap_good(int* a, int* b)` swaps values by passing pointers (addresses), modifying the original variables.

- **Memory Addresses:**  
  - The `&` operator gives the address of a variable.
  - Printing addresses shows how variables are stored in memory (hexadecimal format).

- **Pointers:**  
  - Declaring pointers: `int* g = NULL; int* h;`
  - Uninitialized pointers contain garbage values.
  - Assigning a pointer to a variable's address: `g = &guess;`
  - Dereferencing a pointer: `*g` accesses the value at the address.

- **Pointer Arithmetic:**  
  - Incrementing a pointer (`g++`) moves it to the next memory location for its type.

## Example Output

```
Welcome to pointer tutorial!

Before swap_bad: a=10 b=20
 Inside swap_bad function before swap: a=10 b=20
 Inside swap_bad function after swap: a=20 b=10
After swap_bad: a=10 b=20 ; notice the values did not change

Before swap_good: a=10 b=20
 Inside swap_good function before swap: *a=10 *b=20
 Inside swap_good function after swap: *a=20 *b=10
After swap_good: a=20 b=10

first variable is at address:   0x16b602cd4 with value 10
another variable is at address: 0x16b602cd0 with value 56
guess variable is at address:   0x16b602ccc with value 42
last variable is at address:    0x16b602cc8 with value 99

Notice the address are presented in the hexadecimal format

Pointer g points to address: 0x0
   and pointer h: 0x16b602ef0
 -> notice how h is uninitialized and contains a garbage value (or zero in some cases)

Pointer g now points to address: 0x16b602ccc (guess variable)
Value at address g is pointing to: 42

New value of guess is: 55
Value at address g is pointing to: 55

Pointer g now points to address: 0x16b602cd0 (incremented by the size of type int)
Pointer g now points to another variable
Value at address g is pointing to: 56
```

## How to Run

Compile and run:

```sh
gcc main.c -o pointer-demo
./pointer-demo
```

## Summary

- Use pointers to modify variables in functions.
- Understand memory addresses and pointer arithmetic.
- Always initialize pointers before use.

# Challenge
Implement a function `add_number(a, b, result)` and verify result == a + b