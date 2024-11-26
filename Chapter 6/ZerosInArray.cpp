#include <iostream>

using std::cout;

int zeroCountRecursive(int numbers[], int size) {

    if (size == 0)
        return 0;
    
    int count = zeroCountRecursive(numbers, size - 1);
    if (numbers[size - 1] == 0)
        count++;

    return count;

}

int main() {

    int integers[] = {2, 6, 9, 0};
    cout << zeroCountRecursive(integers, 4) << "\n";

}