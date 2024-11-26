#include <iostream>
#include <string>
using std::cin;
using std::cout;

#define NUMBER_OF_ROWS 8
#define FUNCTION_SEPARATION 4

int main() {

    int currentRowHashes;
    int currentRowSideSpace;

    for (int row = 1; row <= NUMBER_OF_ROWS; row++) {

        std::string outputRow {};

        if (row <= FUNCTION_SEPARATION) {

            currentRowSideSpace = row - 1;
            for (int currentHash = 1; currentHash <= currentRowSideSpace; currentHash++)
                outputRow.append(".");

            outputRow.append("#");

            for (int currentHash = 1; currentHash <= currentRowSideSpace; currentHash++)
                outputRow.append(".");

        }
        else {

            currentRowSideSpace = - row + 8;
            for (int currentHash = 1; currentHash <= currentRowSideSpace; currentHash++)
                outputRow.append(".");

            outputRow.append("#");

            for (int currentHash = 1; currentHash <= currentRowSideSpace; currentHash++)
                outputRow.append(".");

        }

        cout << outputRow;
        cout << "\n";

    }

}