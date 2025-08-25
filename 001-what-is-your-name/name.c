#include <stdio.h>

int main(int argc, char **argv)
{
    /*
    ex: "ls -l" execute the program 'ls' with 2 arguments : 'ls' and '-l'

    "lioma lioma" => 2 arguments : argc = 2 => display Hi lioma


    "lioma papa" => display Hi papa       // argc = 2
    "lioma" => display what is your name? // argc = 1
    "lioma papa mama" => display Hi papa  // argc = 3


    when you provide the name,  the program will display: Hi [name]
    when you don't provide the name, the program will display: What is your name?

    */
    if (argc == 1)
    {
        // this is only executed when argc is equal to 1
        // display what is your name
        printf("what is your name?\n");
        // finish the program
        return 0;
    }
    // display hi [name]
    printf("Hi %s\n", argv[1]);

    return 0;
}