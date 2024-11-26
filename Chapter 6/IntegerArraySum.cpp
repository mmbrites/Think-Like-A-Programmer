#include <iostream>

using std::cout;

int iterativeArraySum(int integers[], int size) {

    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += integers[i];
    return sum;

}

int arraySumDelegate(int integers[], int size) {

    if (size == 0)
        return 0;

    int lastNumber = integers[size - 1];
    int allButLastSum = iterativeArraySum(integers, size - 1);
    return lastNumber + allButLastSum;

}

int arraySumRecursive(int integers[], int size) {

    if (size == 0)
        return 0;

    int lastNumber = integers[size - 1];
    int allButLastSum = arraySumRecursive(integers, size - 1);
    return lastNumber + allButLastSum;

}

int main() {

    int integers[] = {2, 6, 9, 10};
    cout << iterativeArraySum(integers, 4) << "\n";
    cout << arraySumDelegate(integers, 4) << "\n";
    cout << arraySumRecursive(integers, 4) << "\n";

}