#include <iostream>
#include <vector>

int main()
{
    system("cls");
    std::vector<int> wholeNums{-1, 23, -5, 45, 343, 213, 2, 23};

    wholeNums.push_back(1);
    wholeNums.push_back(2);
    wholeNums.push_back(3);
    wholeNums.push_back(4);
    wholeNums.push_back(5);

    std::cout << wholeNums.at(0) << std::endl;
    std::cout << wholeNums[1] << std::endl;
    std::cout << wholeNums[2] << std::endl;
    std::cout << wholeNums[3] << std::endl;
    std::cout << "Size: " << wholeNums.size() << std::endl;
    std::cout << "Capacity: " << wholeNums.capacity() << std::endl;
    wholeNums.push_back(8);
    wholeNums.push_back(9);
    wholeNums.push_back(12);
    wholeNums.push_back(14);

    std::cout << wholeNums.front() << std::endl;
    std::cout << wholeNums.back() << std::endl;
    std::cout << "Size: " << wholeNums.size() << std::endl;
    std::cout << "Capacity: " << wholeNums.capacity() << std::endl;

    // Iterator: object indicating specific element inside a container
    // std::vector<int>::iterator it = wholeNums.begin();

    // while (it != wholeNums.end())
    // {
    //     std::cout << *it << std::endl;
    //     it++;
    // }

    // for (auto it = wholeNums.begin(); it != wholeNums.end(); it++)
    // {
    //     std::cout << *it << std::endl;
    // }

    // for (auto &nr : wholeNums)
    // {
    //     nr *= 10;
    //     std::cout << nr << std::endl;
    // }

    for (const auto &nr : wholeNums)
    {
        std::cout << nr << std::endl;
    }

    return 0;
}