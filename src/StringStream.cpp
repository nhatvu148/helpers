#include <iostream>
#include <sstream>
#include <string>
#include <limits>
#include <new>

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

    do
    {
        std::cout << "Do you want to close the program? (Y/N)" << std::endl;
        std::cin >> input;
    } while (input != "y" && input != "Y");

    std::cout << *(new int) << std::endl;
    std::cout << new int << std::endl;

    {
        int *p = new int;
        *p = 100;
        std::cout << p << std::endl;
        std::cout << *p << std::endl;

        delete p;
        p = new int;
        std::cout << p << std::endl;

        delete p;
        p = new int[12345];
        std::cout << p << std::endl;

        p = NULL;

        if (p != NULL)
        {
            *p = 120;
            std::cout << *p << std::endl;
        }
    }

    int amount;
    std::cout << "How many numbers would you like to store in an array?" << std::endl;
    std::cin >> amount;
    int *p = new (std::nothrow) int[amount];
    if (p != NULL)
    {
        for (int i = 0; i < amount; i++)
        {
            std::cout << "Enter the " << (i + 1) << " number: " << std::endl;
            std::cin >> p[i];
        }

        for (int i = 0; i < amount; i++)
        {
            std::cout << "p[" << i << "] = " << p[i] << std::endl;
        }
    }
    else
    {
        std::cout << "Not enough memory!" << std::endl;
    }

    std::string mystring = "Hello world!";
    const char *mychar = mystring.c_str();
    std::cout << mychar << std::endl;

    char mychar2[] = "Hello world!";
    std::string mystring2 = mychar2;
    std::cout << mystring2 << std::endl;

    // If loop inscription pointer without const ==> leak memory
    // even after delete[] because incription has incremented by using **
    // also has to use tempoPointer as incrementer
    char *const inscription = new char[20];
    inscription[0] = 'a';
    inscription[1] = 'e';
    inscription[2] = 'r';
    inscription[3] = 'o';
    inscription[4] = '\0';

    char *tempoPointer = inscription;

    while (*tempoPointer)
    {
        std::cout << *tempoPointer++;
    }
    delete[] inscription;

    return 0;
}