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

            outputRow.append("#");

            currentRowMidSpace = -2 * row + 7;
            for (int currentSpace = 1; currentSpace <= currentRowMidSpace; currentSpace++)
                outputRow.append(".");

            outputRow.append("#");

        }
        else if (row <= UPPER_MID) {

            outputRow.append("#");

            currentRowMidSpace = 2 * row - 9;
            for (int currentSpace = 1; currentSpace <= currentRowMidSpace; currentSpace++)
                outputRow.append(".");

            outputRow.append("#");

        }
        else if (row <= LOWER_MID) {

            outputRow.append("#");

            currentRowMidSpace = -2 * row + 17;
            for (int currentSpace = 1; currentSpace <= currentRowMidSpace; currentSpace++)
                outputRow.append(".");

            outputRow.append("#");

        }
        else {

            outputRow.append("#");

            currentRowMidSpace = 2 * row - 19;
            for (int currentSpace = 1; currentSpace <= currentRowMidSpace; currentSpace++)
                outputRow.append(".");

            outputRow.append("#");

        }

        cout << outputRow;
        cout << "\n";

    }

}