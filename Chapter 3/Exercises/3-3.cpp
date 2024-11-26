#include <iostream>
using std::cout;

bool isArraySorted(int* array, int numberOfElements) {

    for (int i = 1; i < numberOfElements; i++)
        if (array[i - 1] > array[i])
            return false;

    return true;

}

int main() {

    const int ARRAY_SIZE = 12;
    int array[ARRAY_SIZE] = {1856, 498, 30924, 87478, 328, 2653, 387, 3754, 387587, 2873, 276, 32};
    
    if (ARRAY_SIZE > 1)
        if (isArraySorted(array, ARRAY_SIZE))
            cout << "Array is sorted!\n";
        else
            cout << "Array is not sorted!\n";
    else
        cout << "Array is sorted!\n";

}