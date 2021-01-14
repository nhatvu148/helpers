#include <iostream>
#include <string>
#include <cstring>

int main(int argc, char *argv[])
{
    std::cout << "Number of input args: " << argc << std::endl;
    for (int i = 0; i < argc; i++)
    {
        printf("Arg number %d is %s\n", i, argv[i]);
        // if (std::string(argv[i]) == "-h")
        if (strcmp(argv[i], "-h") == 0)
        {
            printf("Help!!\n");
        }
    }

    int *pointer = 0;
    int size = 50000;
    pointer = (int *)malloc(size);
    std::cout << pointer << std::endl;

    int *p = new int;
    *p = 50;
    std::cout << p << std::endl;
    std::cout << *p << std::endl;

    delete p;

    // will crash if other programs use this memory location:
    *p = 20;
    std::cout << p << std::endl;

    std::cout << *p << std::endl;

    char myArr[] = "Ham\0burger";
    char *ptr = myArr;
    std::cout << *ptr << std::endl;
    std::cout << ptr << std::endl;

    return 0;
}