#include <iostream>
#include <string>
using std::cin;
using std::cout;

#define NUMBER_OF_ROWS 8
#define FUNCTION_SEPARATION 4

int main() {

    int currentRowSideSpace;
    int currentRowHashes;
    int currentRowMidSpace;

    for (int row = 1; row <= NUMBER_OF_ROWS; row++) {

        std::string outputRow {};

        if (row <= FUNCTION_SEPARATION) {

            currentRowSideSpace = row - 1;
            for (int currentSpace = 1; currentSpace <= currentRowSideSpace; currentSpace++)
                outputRow.append(" ");

            currentRowHashes = 2 * row;
            for (int currentHash = 1; currentHash <= currentRowHashes / 2 /* Divide by 2 due to mid space */; currentHash++)
                outputRow.append("#");
                
            currentRowMidSpace = -4 * row + 16;
            for (int currentSpace = 1; currentSpace <= currentRowMidSpace; currentSpace++)
                outputRow.append(" ");

            for (int currentHash = 1; currentHash <= currentRowHashes / 2 /* Divide by 2 due to mid space */; currentHash++)
                outputRow.append("#");

            for (int currentSpace = 1; currentSpace <= currentRowSideSpace; currentSpace++)
                outputRow.append(" ");

        }
        else {

            currentRowSideSpace = - row + 8;
            for (int currentSpace = 1; currentSpace <= currentRowSideSpace; currentSpace++)
                outputRow.append(" ");

            currentRowHashes = -2 * row + 18;
            for (int currentHash = 1; currentHash <= currentRowHashes / 2 /* Divide by 2 due to mid space */; currentHash++)
                outputRow.append("#");

            currentRowMidSpace = 4 * row - 20;
            for (int currentSpace = 1; currentSpace <= currentRowMidSpace; currentSpace++)
                outputRow.append(" ");

            for (int currentHash = 1; currentHash <= currentRowHashes / 2 /* Divide by 2 due to mid space */; currentHash++)
                outputRow.append("#");

            for (int currentSpace = 1; currentSpace <= currentRowSideSpace; currentSpace++)
                outputRow.append(" ");

        }

        cout << outputRow;
        cout << "\n";

    }

}