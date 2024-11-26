#include <iostream>

using std::cout;

bool oddParityIterative(int array[], int size) {

    int countOnes = 0;
    for (int i = 0; i < size; i++)
        if (array[i] == 1)
            countOnes++;

    if (countOnes % 2 == 0)
        return false;
    return true;

}

bool oddParity(int array[], int size) {

    if (size == 0)
        return false;

    bool odd = oddParity(array, size - 1);

    if (array[size - 1] == 1)
        odd = !odd;

    return odd;

}

int main() {

    int array[] = {1, 1, 1};
    cout << oddParity(array, 3) << "\n"; // REMEMBER, OUTPUTTING A NUMBER OTHER THAN 0 IS EQUAL TO TRUE, 0 IS EQUAL TO FALSE

}