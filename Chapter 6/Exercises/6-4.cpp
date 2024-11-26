#include <iostream>

using std::cout;

int * compareTriplets(int a[], int b[], int size) {
    
    int * results = new int[2];
    for (int i = 0; i < size; i++) {
     
        if (a[i] > b[i])
            results[0]++;
        else if (a[i] < b[i])
            results[1]++;
        
    }
    
    return results;

}

int * compareTripletsRecursive(int a[], int b[], int size) {

    if (size == 0)
        return new int[2];

    int * results = compareTriplets(a, b, size - 1);
    if (a[size - 1] > b[size - 1])
        results[0]++;
    else if (a[size - 1] < b[size - 1])
        results[1]++;

    return results;

}

int main() {

    int alice[] = {1, 2, 1};
    int bob[] = {0, 2, 1};

    int * results = compareTripletsRecursive(alice, bob, 3);
    for (int i = 0; i < 2; i++)
        cout << results[i] << "\n";

    delete[] results;
    results = nullptr;

}