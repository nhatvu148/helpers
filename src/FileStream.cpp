#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::fstream file;

    // file.open("Test.txt", std::ios::out | std::ios::app);
    file.open("Test.txt", std::ios::in);

    // std::ios::out => Input, reading
    // std::ios::in => Output, write to file, if there is no file then create it,
    // if there is a file then truncate it (remove content) unless it occurs with ios::in flag
    // std::ios::trunc => Truncate
    // std::ios::ate => At the end, set pointer at the end of file - the place of pointer can be changed
    // possible to read and write in this mode
    // std::ios::app => Append, the content is added at the end of file, not possible to remove content
    // nor adding something in other places
    // std::ios::binary => open file as binary file

    // Defautl mode flags:
    // fstream - ios::out | ios::in
    // ifstream - ios::in
    // ofstream - ios::out

    // Error flags:
    // bad() - badbit(1) - returns true if there is an error like writing to file which was opened only for reading (ios::in)
    // clear() - clear state
    // good() - goodbit(0)
    // eof() - eofbit(2)
    // fail() - failbit(4) - return true if try to assign string to integer while reading from file or when batbit situation happens
    // 1 - 001; 2 - 010; 4 - 100
    // bitwise operators: & | ^
    // rdstate() - read state

    // tellg - tell get - tell where the reading pointer is
    // seekg - seek get - set reading pointer at specified position
    // seekg(how_many_bytes_from_the_flag_place, flag)
    // possible flags:
    // ios::beg
    // ios::end
    // ios::cur

    // tellp - tell put - tell where the putting pointer is
    // seekp - seek put - set writing (putting) pointer at specified position
    // seekp(how_many_bytes_from_the_flag_place, flag)

    // getline()
    // get()
    // ignore()
    // read()
    // memcmp()
    // put()
    // peek()
    // putback()
    // write()

    if (file.is_open())
    {
        std::cout << "The file has been opened properly.\n";
        // file << "This is a sample text\n";

        std::string buffer;
        file.seekg(-5, std::ios::end);
        std::streampos sizeOfFile = file.tellg();
        file.seekg(0, std::ios::beg);
        std::cout << file.tellg() << std::endl;

        std::cout << "The size of the file is " << sizeOfFile << " bytes" << std::endl;

        do
        {
            std::cout << file.tellg() << std::endl;
            file >> buffer;
            std::cout << buffer << std::endl;
        } while (!file.eof());

        if ((file.rdstate() ^ std::ifstream::eofbit) == 0)
        {
            file.clear();
        }
        std::cout << file.rdstate() << std::endl;
    }
    else
    {
        std::cout << "The file has not been opened properly.\n";
    }
    file.close();

    system("cls");
    system("dir");

    return 0;
}