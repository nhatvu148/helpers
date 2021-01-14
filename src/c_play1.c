#include <stdio.h>

extern int my_var;
int getVar()
{
    auto int x = 10;
    static int y = 10;
    y++;
    printf("%i\n", x);
    printf("%i\n", y);
    my_var = 121;
    return my_var + 123;
}