#include <iostream>
#include <fstream>

#pragma pack(push, 1)

struct Person
{
    char name[50];
    int age;
    double height;
};

#pragma pack(pop)

int main()
{
    std::cout << sizeof(Person) << std::endl;
    std::string inFileName = "test.txt";

    Person someone = {"Nhat Vu", 30, 1.8};
    std::string inBinName = "test.bin";

    std::ifstream inFile;
    inFile.open(inFileName);

    //// WRITE BINARY FILE ////
    std::ofstream outFile;
    outFile.open(inBinName, std::ios::binary);

    if (outFile.is_open())
    {
        outFile.write(reinterpret_cast<char *>(&someone), sizeof(Person));
        outFile.close();
    }
    else
    {
        std::cout << "Cannot create file: " << inBinName << std::endl;
    }

    //// READ BINARY FILE ////
    Person someoneElse = {};

    std::ifstream inputFile;
    inputFile.open(inBinName, std::ios::binary);

    if (inputFile.is_open())
    {
        inputFile.read(reinterpret_cast<char *>(&someoneElse), sizeof(Person));
        inputFile.close();
    }
    else
    {
        std::cout << "Cannot read file: " << inBinName << std::endl;
    }
    std::cout << someoneElse.name << ", " << someoneElse.age << ", " << someoneElse.height << ", " << std::endl;

    if (inFile.is_open())
    {
        std::string line;

        while (inFile)
        {
            std::getline(inFile, line, ':');

            int population;
            inFile >> population;
            // inFile.get();
            inFile >> std::ws;

            if (!inFile)
            {
                break;
            }

            std::cout << "'" << line << "'"
                      << " -- '" << population << "'" << std::endl;
        }

        inFile.close();
    }
    else
    {
        std::cout << "Cannot open file: " << inFileName << std::endl;
    }
    return 0;
}