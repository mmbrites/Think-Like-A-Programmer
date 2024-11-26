#include <iostream>
using std::cout;

int compareFunc(const void* voidA, const void* voidB) {

    int * intA = (int *)(voidA);
    int * intB = (int *)(voidB);

    return *intA - *intB;

}

int main() {

    const int ARRAY_SIZE = 12;
    int surveyData[ARRAY_SIZE] = {4, 7, 3, 8, 9, 7, 3, 9, 9, 3, 3, 10};

    const int MAX_RESPONSE = 10;
    int histogram[MAX_RESPONSE];

    for (int i = 0; i < MAX_RESPONSE; i++)
        histogram[i] = 0;

    for (int i = 0; i < ARRAY_SIZE; i++)
        histogram[surveyData[i] - 1]++;

    int mostFrequent = 0;
    for (int i = 1; i < MAX_RESPONSE; i++)
        if (histogram[i] > histogram[mostFrequent])
            mostFrequent = i;

    mostFrequent++;

    cout << "Mode: " << mostFrequent << "\n";
    cout << mostFrequent << " appears " << histogram[mostFrequent - 1] << " times!\n";

}