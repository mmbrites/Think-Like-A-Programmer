#include <iostream>
#include <string>
using std::cin;
using std::cout;

#define NUMBER_OF_ROWS 8
#define FUNCTION_SEPARATION 4

int main() {

    int currentRowHashes;

    for (int row = 1; row <= NUMBER_OF_ROWS; row++) {

        std::string outputRow {};

        if (row <= FUNCTION_SEPARATION) {

            currentRowHashes = 2 * row;
            for (int currentHash = 1; currentHash <= currentRowHashes; currentHash++)
                outputRow.append("#");

        }
        else {

            currentRowHashes = -2 * row + 18;
            for (int currentHash = 1; currentHash <= currentRowHashes; currentHash++)
                outputRow.append("#");

        }

        cout << outputRow;
        cout << "\n";

    }

}