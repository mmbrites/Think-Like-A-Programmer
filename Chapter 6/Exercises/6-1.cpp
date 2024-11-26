#include <iostream>

using std::cout;

int positiveNumbersSumIterative(int array[], int size) {

    int sum = 0;
    for (int i = 0; i < size; i++)
        if (array[i] >= 0)
            sum += array[i];

    return sum;

}

int positiveNumbersSumRecursive(int array[], int size) {

    if (size == 0)
        return 0;

    int sum = positiveNumbersSumRecursive(array, size - 1);
    if (array[size - 1] > 0)
        sum += array[size - 1];
    return sum;

}

int main() {

    int array[] = {0, 2, -3};
    cout << positiveNumbersSumIterative(array, 3) << "\n";
    cout << positiveNumbersSumRecursive(array, 3) << "\n";

}