#include <iostream>
#include <string>
using std::cin;
using std::cout;

#define NUMBER_OF_ROWS 8
#define FUNCTION_SEPARATION 4

int main() {

    int currentRowHashes;
    int currentRowSpace;

    for (int row = 1; row <= NUMBER_OF_ROWS; row++) {

        std::string outputRow {};

        if (row <= FUNCTION_SEPARATION) {

            currentRowSpace = -2 * row + 8; // algebraic expression found
            for (int currentHash = 1; currentHash <= currentRowSpace / 2 /* Beginning space */; currentHash++)
                outputRow.append(" ");

            currentRowHashes = 2 * row; // algebraic expression found!
            for (int currentHash = 1; currentHash <= currentRowHashes; currentHash++)
                outputRow.append("#");

            for (int currentHash = 1; currentHash <= currentRowSpace / 2 /* Ending space */; currentHash++)
                outputRow.append(" ");

        }
        else {

            currentRowSpace = 2 * row - 10; // algebraic expression found
            for (int currentHash = 1; currentHash <= currentRowSpace / 2 /* Beginning space */; currentHash++)
                outputRow.append(" ");

            currentRowHashes = -2 * row + 18; // algebraic expression found!
            for (int currentHash = 1; currentHash <= currentRowHashes; currentHash++)
                outputRow.append("#");

            for (int currentHash = 1; currentHash <= currentRowSpace / 2 /* Ending space */; currentHash++)
                outputRow.append(" ");

        }

        cout << outputRow;
        cout << "\n";

    }

}