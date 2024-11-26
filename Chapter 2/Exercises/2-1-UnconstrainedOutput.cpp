#include <iostream>
using std::cin;
using std::cout;

#define NUMBER_OF_ROWS 4

int main() {

    int currentRowHashes;
    int currentRowSpace;

    for (int row = 1; row <= NUMBER_OF_ROWS; row++) {

        currentRowSpace = 2 * row - 2; // algebraic expression found
        for (int currentHash = 1; currentHash <= currentRowSpace / 2 /* Beginning space */; currentHash++)
            cout << " ";

        currentRowHashes = -2 * row + 10; // algebraic expression found!
        for (int currentHash = 1; currentHash <= currentRowHashes; currentHash++)
            cout << "#";

        for (int currentHash = 1; currentHash <= currentRowSpace / 2 /* Ending space */; currentHash++)
            cout << " ";

        cout << "\n";

    }

}