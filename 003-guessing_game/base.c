#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int main(int argc, char **argv)
{
    printf("Welcome to guessing game!\n");

    printf("Provide a number between 0 and 100 : ");
    // Create a variable to hold the user's guess
    int guess = 0;

    // Read the user's guess from standard input (keyboard)
    // and store the value in the 'guess' variable
    // & is the address-of operator, we tell the function where to store the value by address
    scanf("%d", &guess);

    printf("You guessed: %d\n", guess);

    // Seed the random number generator
    // removing this line will always generate the same number
    srand((unsigned int)time(NULL));

    // Generate a random number between 0 and 100
    // in this context, % is the modulo operator
    int secret = rand() % 101;

    printf("The secret number is: %d\n", secret);

    return 0;
}