#include <stdio.h>
/*
List all the arguments provided to the program
*/
int main(int argc,char **argv) {
    
    printf("Number of argument: %d\n", argc);
    // for ( [initial statement] ; [condition to continue the loop] ; [instruction to do at the end of the loop])
    // i++ means we increment i variable by 1 ; same as i = i + 1
    for (int i = 0; i < argc;i++) {
        printf(
            "argument %d/%d: %s \n",
            i + 1,
            argc,
            argv[i]
        );
    }
    return 0;
}