#include <fstream>
#include <iostream>
using namespace std;

// ofstream outfile;
// outfile.open("file.dat", ios::out | ios::trunc );
// ios::app // Append mode. All output to that file to be appended to the end.
// ios::ate // Open a file for output and move the read/write control to the end of the file.
// ios::in // Open a file for reading.
// ios::out // Open a file for writing.
// ios::trunc // If the file already exists, its contents will be truncated before opening the file.

int main()
{
    char data[100];

    // open a file in write mode.
    ofstream outfile;
    outfile.open("afile.dat");

    cout << "Writing to the file" << endl;
    cout << "Enter your name: ";
    cin.getline(data, 100);

    // write inputted data into the file.
    outfile << data << endl;

    cout << "Enter your age: ";
    cin >> data;
    cin.ignore();

    // again write inputted data into the file.
    outfile << data << endl;

    // close the opened file.
    outfile.close();

    // open a file in read mode.
    ifstream infile;
    infile.open("afile.dat");

    cout << "Reading from the file" << endl;
    infile >> data;

    // write the data at the screen.
    cout << data << endl;

    // again read the data from the file and display it.
    infile >> data;
    cout << data << endl;

    // close the opened file.
    infile.close();

    return 0;
}