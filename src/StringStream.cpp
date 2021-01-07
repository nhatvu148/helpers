#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string name = "Nhat Vu";
    int age = 30;

    std::stringstream ss;
    ss << "My name is ";
    ss << name;
    ss << "; My age is ";
    ss << age;

    std::string info = ss.str();

    std::cout << info << std::endl;
    std::cout << "My name is " << name << " and I'm " << age << std::endl;

    return 0;
}