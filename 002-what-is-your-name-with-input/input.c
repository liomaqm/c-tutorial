#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    /**
     * Create a char array (list of characters) to hold the name.
     * We allocate 100 characters, which should be enough for most names.
     * 
     * Note that this is not a string yet, just a list of characters.
     * In C, strings are represented as arrays of characters ending with a null character '\0'.
     */
    char name[100];

    // Initialize the array to an empty string
    // Now referencing name as a string is safe
    name[0] = '\0'; 

    printf("What is your name ? ");
    fgets(&name[0], sizeof(name), stdin);

    // Remove newline character if present

    // strlen computes the length of the string (not counting the null terminator)
    // to do so, strlen scans the array until it finds the null terminator ('\0')
    size_t len = strlen(name);
    if (len > 0 && name[len - 1] == '\n') {
        name[len - 1] = '\0';
    }

    printf("Hi %s !\n", name);
    return 0;
}