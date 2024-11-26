#include <iostream>
#include <string>
using std::cin;
using std::cout;

#define NUMBER_OF_ROWS 12
#define UPPER 4
#define UPPER_MID 6
#define LOWER_MID 8
// It is not necessary to declare a "LOWER" constant since the "else" branch covers it

/* 

    Drawing Pattern:

    #     #
     #   #
      # #
       #
      # #
     #   #
     #   #
      # #
       #
      # #
     #   #
    #     #

*/

int main() {

    int currentRowSideSpace;
    int currentRowHashes;
    int currentRowMidSpace;

    for (int row = 1; row <= NUMBER_OF_ROWS; row++) {

        std::string outputRow {};

        if (row <= UPPER) {

            currentRowSideSpace = row - 1;
            for (int currentSpace = 1; currentSpace <= currentRowSideSpace; currentSpace++)
                outputRow.append(".");

            outputRow.append("#");

            for (int currentSpace = 1; currentSpace <= currentRowSideSpace; currentSpace++)
                outputRow.append(".");

        }
        else if (row <= UPPER_MID) {

            currentRowSideSpace = - row + 7;
            for (int currentSpace = 1; currentSpace <= currentRowSideSpace; currentSpace++)
                outputRow.append(".");

            outputRow.append("#");

            for (int currentSpace = 1; currentSpace <= currentRowSideSpace; currentSpace++)
                outputRow.append(".");

        }
        else if (row <= LOWER_MID) {

            currentRowSideSpace = row - 6;
            for (int currentSpace = 1; currentSpace <= currentRowSideSpace; currentSpace++)
                outputRow.append(".");

            outputRow.append("#");

            for (int currentSpace = 1; currentSpace <= currentRowSideSpace; currentSpace++)
                outputRow.append(".");

        }
        else {

            currentRowSideSpace = - row + 12;
            for (int currentSpace = 1; currentSpace <= currentRowSideSpace; currentSpace++)
                outputRow.append(".");

            outputRow.append("#");

            for (int currentSpace = 1; currentSpace <= currentRowSideSpace; currentSpace++)
                outputRow.append(".");

        }

        cout << outputRow;
        cout << "\n";

    }

}