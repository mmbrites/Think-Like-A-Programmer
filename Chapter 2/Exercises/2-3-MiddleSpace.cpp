#include <iostream>
#include <string>
using std::cin;
using std::cout;

#define NUMBER_OF_ROWS 8
#define FUNCTION_SEPARATION 4

int main() {
    
    int currentRowHashes;
    int currentRowMidSpace;

    for (int row = 1; row <= NUMBER_OF_ROWS; row++) {

        std::string outputRow {};

        if (row <= FUNCTION_SEPARATION) {

            currentRowMidSpace = -4 * row + 16;
            outputRow.append("#");

            for (int currentHash = 1; currentHash <= currentRowMidSpace; currentHash++)
                outputRow.append(" ");

            outputRow.append("#");

        }
        else {

            currentRowMidSpace = 4 * row - 20;
            outputRow.append("#");

            for (int currentHash = 1; currentHash <= currentRowMidSpace; currentHash++)
                outputRow.append(" ");

            outputRow.append("#");

        }

        cout << outputRow;
        cout << "\n";

    }

}