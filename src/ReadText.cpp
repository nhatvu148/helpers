#include <iostream>
#include <fstream>

int main()
{
    std::string inFileName = "test.txt";

    std::ifstream inFile;

    inFile.open(inFileName);

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