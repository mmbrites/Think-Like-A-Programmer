#include <iostream>
using std::cin;
using std::cout;

#define NUMBER_OF_HASHES_PER_ROWS 4
#define NUMBER_OF_ROWS 7

int main() {

    int currentRowHashes;

    for (int row = 1; row <= NUMBER_OF_ROWS; row++) {

        currentRowHashes = NUMBER_OF_HASHES_PER_ROWS - abs(NUMBER_OF_HASHES_PER_ROWS - row);
        for (int currentHash = 1; currentHash <= currentRowHashes; currentHash++)
            cout << "#";

        cout << "\n";

    }

}