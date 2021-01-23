#include <iostream>

void increment_all(int *start, int *stop)
{
    int *current = start;
    while (current != stop)
    {
        ++(*current); // increment value pointed
        ++current;    // increment pointer
    }
}

void print_all(const int *start, const int *stop)
{
    const int *current = start;
    while (current != stop)
    {
        std::cout << *current << '\n';
        ++current; // increment pointer
    }
}

int addition(int a, int b)
{
    return (a + b);
}

int subtraction(int a, int b)
{
    return (a - b);
}

int operation(int x, int y, int (*functocall)(int, int))
{
    int g;
    g = (*functocall)(x, y);
    return (g);
}

int main()
{
    int numbers[] = {10, 20, 30};
    increment_all(numbers, numbers + 3);
    print_all(numbers, numbers + 3);

    int m, n;
    int (*minus)(int, int) = subtraction;

    m = operation(7, 5, addition);
    n = operation(20, m, minus);
    std::cout << n;

    int *foo;
    foo = new int[5];
    // foo[0] or *foo
    // foo[1] or *(foo+1)
    // the size of a regular array needs to be a constant expression, and thus its size has to be determined at the moment of designing the program, before it is run, whereas the dynamic memory allocation performed by new allows to assign memory during runtime using any variable value as size
    
    return 0;
}