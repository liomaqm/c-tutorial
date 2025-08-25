#include <stdio.h>

/*
To build this program:
- Open the terminal in the folder 000-basic-program
- Run the command `mkdir .build` to create a folder named .build
- Run the command `cd .build` to go into the folder .build
- Run the command `cmake ..` to generate the Makefile
- Run the command `make` to build the program
- Run the command `./basic_program` to execute the program

Once this is done once, you can simply run `make` to rebuild the program after making changes to the code, and
 `./basic_program` to execute it.

`./basic_program` means "execute the program named basic_program in the current folder (.)"
`./basic_program arg1 arg2` means "execute the program named basic_program in the current folder (.) with 2 arguments: arg1 and arg2"
*/

// This function is executed when the program starts
// argc: number of argument (see above)
// argv: vector (list) of argument (argv[0] is the name of the program, argv[1] is the first argument, etc.)
int main(int argc, char **argv)
{
    // display Hello World! in the terminal
    printf("Hello World!\n");

    /*
      display the number of argument
      %d is a placeholder for an integer (number)
       \n means new line (go to the next line)
    */
    printf("Number of argument: %d\n", argc);

    // return 0 means the program finished sucessfully
    return 0;
}