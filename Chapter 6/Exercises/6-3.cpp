#include <iostream>

using std::cout;

int targetOccurrencesIterative(int array[], int size, int target) {

    int occurences = 0;
    for (int i = 0; i < size; i++)
        if (array[i] == target)
            occurences++;

    return occurences;

}

int targetOccurrencesRecursive(int array[], int size, int target) {

    if (size == 0)
        return 0;

    int occurrences = targetOccurrencesRecursive(array, size - 1, target);
    if (array[size - 1] == target)
        occurrences++;

    return occurrences;

}

int main() {

    int array[] = {1, 1, 1, 5, 9, 1};
    cout << targetOccurrencesRecursive(array, 6, 9) << "\n";

}