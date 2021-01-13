#include <iostream>
#include <sstream>
#include <string>
#include <limits>

int main()
{
    std::string name = "Nhat Vu";
    int age = 30;

    std::stringstream ss;
    ss << "My name is ";
    ss << name;
    ss << "; My age is ";
    ss << age;

    std::string info = ss.str();
    std::cout.width(100);
    std::cout << info << std::endl;
    std::cout.fill('x');
    std::cout.width(50);
    std::cout << std::left << "Hiii!";
    std::cout << "My name is " << name << " and I'm " << age << std::endl;

    std::string fruitList[] = {"Apple", "Orange", "Banana"};
    std::string input;
    std::cout << "What do you like better?\n";
    std::cout << "1. An Apple\n";
    std::cout << "2. An Orange\n";
    std::cout << "3. A Banana\n";
    do
    {
        std::cin >> input;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "You have chosen " << ((input == "1" || input == "2" || input == "3") ? fruitList[std::stoi(input) - 1] : "Invalid input!") << std::endl;
        if (input != "1" && input != "2" && input != "3")
        {
            std::cout << "Please choose a valid option!\n";
        }
    } while (input != "1" && input != "2" && input != "3");

    return 0;
}