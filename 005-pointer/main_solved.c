#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief Swap two integers - this function does not work as expected
 * 
 * In C, function parameters are passed by value.
 * This means that the function receives a copy of the arguments.
 * Any changes made to the parameters inside the function
 * do not affect the original arguments in the caller.
 */
void swap_bad(int a, int b) {
    int temp = a;
    printf(" Inside swap_bad function before swap: a=%d b=%d\n", a, b);
    // This will only swap the local copies of a and b
    // The original variables in the caller will not be affected
    // because C uses pass-by-value semantics
    a = b;
    b = temp;
    printf(" Inside swap_bad function after swap: a=%d b=%d\n", a, b);
}

void add_number(int a, int b, int* result) {
    *result = a + b;
}

/**
 * @brief Swap two integers by using pointers
 * 
 * 
 */
void swap_good(int* a, int* b) {
    int temp = *a;
    printf(" Inside swap_good function before swap: *a=%d *b=%d\n", *a, *b);
    *a = *b;
    *b = temp;
    printf(" Inside swap_good function after swap: *a=%d *b=%d\n", *a, *b);
}

int main(int argc, char **argv)
{
    printf("Welcome to pointer tutorial!\n\n");

    int a = 10;
    int b = 20;
    printf("Before swap_bad: a=%d b=%d\n", a, b);
    // This will not swap the values of a and b in main
    // because we are passing a copy of the values a/b to the function swap_bad.
    swap_bad(a, b);
    printf("After swap_bad: a=%d b=%d ; notice the values did not change\n\n", a, b);

    printf("Before swap_good: a=%d b=%d\n", a, b);
    // This will swap the values of a and b in main
    // because we are passing the addresses of a/b to the function swap_good.
    swap_good(&a, &b);
    printf("After swap_good: a=%d b=%d\n\n", a, b);

    // Challenge: implement the function in the commented code below
    // void add_number(a, b, result);
    // that adds two integers a and b and stores the result in the variable result
    // int a, b, result;
    // Call the function and verify that `result = a + b`

    // create multiple variable on the stack
    int first = 10;
    int another = 56;
    int guess = 42;
    int last = 99;
   

    // & is the address-of operator that gives the memory address of a variable
    printf("first variable is at address:   %8p with value %d\n", (void*)&first, first);
    printf("another variable is at address: %8p with value %d\n", (void*)&another, another);
    printf("guess variable is at address:   %8p with value %d\n", (void*)&guess, guess);
    printf("last variable is at address:    %8p with value %d\n\n", (void*)&last, last);
    
    printf("Notice the address are presented in the hexadecimal format\n\n");


    // Create a pointer to an integer and initialize it to NULL
    int* g = NULL;
    int* h;

    // (void*) cast is used to avoid compiler warnings when printing pointers
    // cast means forcing a type conversion
    printf("Pointer g points to address: %p\n   and pointer h: %p\n", (void*)g, (void*)h);
    printf(" -> notice how h is uninitialized and contains a garbage value (or zero in some cases)\n\n");

    // Make the pointer point to the address of the guess variable
    g = &guess;
    printf("Pointer g now points to address: %p (guess variable)\n", (void*)g);
    printf("Value at address g is pointing to: %d\n\n", *g);

    // Change the value of guess using the pointer
    *g = 55;
    printf("New value of guess is: %d\n", guess);
    printf("Value at address g is pointing to: %d\n\n", *g);

    // Make the pointer point to another storage location
    g++; // Increment the pointer to point to the next integer location
    printf("Pointer g now points to address: %p (incremented by the size of type int)\n", (void*)g);
    if (g == &another) {
        printf("Pointer g now points to another variable\n");
        printf("Value at address g is pointing to: %d\n", *g);
    } else {
        printf("Pointer g does not point to another variable\n");
    }
    a = 11;
    b = 31;
    int result = 0;
    add_number(a, b, &result);
    printf("\nThe result of adding %d and %d is %d\n", a, b, result);
    return 0;
}