#include <iostream>
#include <string>
using std::cin;
using std::cout;

#define NUMBER_OF_ROWS 4

int main() {

    int currentRowHashes;
    int currentRowSpace;

    std::string outputRow {};

    for (int row = 1; row <= NUMBER_OF_ROWS; row++) {

        std::string outputRow {};

        currentRowSpace = 2 * row - 2; // algebraic expression found
        for (int currentHash = 1; currentHash <= currentRowSpace / 2 /* Beginning space */; currentHash++)
            outputRow.append(" ");

        currentRowHashes = -2 * row + 10; // algebraic expression found!
        for (int currentHash = 1; currentHash <= currentRowHashes; currentHash++)
            outputRow.append("#");

        for (int currentHash = 1; currentHash <= currentRowSpace / 2 /* Ending space */; currentHash++)
            cout << " ";

        cout << outputRow;

        cout << "\n";

    }

}