#include <iostream>
#include <string>

int main()
{
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