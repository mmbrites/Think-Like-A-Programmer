#include <iostream>
#include <fstream>

using std::cout;
using std::ofstream;

void stackOverflow(ofstream & MyFile) {

    int count = 0;
    MyFile << &count << "\n";
    count++;
    stackOverflow(MyFile);

}

// Crude way to obtain a stack size! The first line of output in the file corresponds to the first stack address used (the highest), and the last line of output in the file corresponds to the last stack address used (the lowest).
// We reached the conclusion that the allocated stack size is rought 8MB.
int main() {

    // Create and open a text file
    ofstream MyFile("filename.txt");
    stackOverflow(MyFile);
    // Close the file
    MyFile.close();
    return 0;

}