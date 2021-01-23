#include <iostream>
#include <string>
#include <sstream>

template <class T>
T sum(T a, T b)
{
    T result;
    result = a + b;
    return result;
}
template <class T, class U>
bool are_equal(T a, U b)
{
    return (a == b);
}
template <class T, int N>
T fixed_multiply(T val)
{
    return val * N;
}

int main()
{
    std::string mystr;
    std::cout << "What's your name? ";
    std::getline(std::cin, mystr);
    std::cout << "Hello " << mystr << ".\n";
    std::cout << "What is your favorite team? ";
    std::getline(std::cin, mystr);
    std::cout << "I like " << mystr << " too!\n";

    float price = 0;
    int quantity = 0;

    std::cout << "Enter price: ";
    std::getline(std::cin, mystr);
    std::stringstream(mystr) >> price;
    std::cout << "Enter quantity: ";
    std::getline(std::cin, mystr);
    std::stringstream(mystr) >> quantity;
    std::cout << "Total price: " << price * quantity << std::endl;

    int i = 5, j = 6, k;
    double f = 2.0, g = 0.5, h;
    k = sum<int>(i, j);
    h = sum<double>(f, g);
    std::cout << k << '\n';
    std::cout << h << '\n';

    if (are_equal(10, 10.0))
        std::cout << "x and y are equal\n";
    else
        std::cout << "x and y are not equal\n";

    std::cout << std::boolalpha;
    std::cout << are_equal<int, double>(10, 10.0) << std::endl;
    std::cout << fixed_multiply<int, 2>(10) << '\n';
    std::cout << fixed_multiply<int, 3>(10) << '\n';

    return 0;
}