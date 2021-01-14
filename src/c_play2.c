#include <stdio.h>
// #include "c_play1.h"

// use extern instead of header file

int my_var;
extern int getVar();

void main()
{
    my_var = getVar();
    getVar();
    getVar();
    printf("The external variable is %i\n", my_var);
    printf("Enter a number: \n");
    size_t rows = 0;
    scanf("%zd", &rows);
    printf("You just typed %d\n", rows);
}