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

    qsort(surveyData, ARRAY_SIZE, sizeof(int), compareFunc);

    int mostFrequent;
    int highestFrequency = 0;
    int currentFrequency = 0;

    for (int i = 0; i < ARRAY_SIZE; i++) {

        currentFrequency++;

        // if (surveyData[i] IS LAST OCCURENCE OF A VALUE)
        if (i == ARRAY_SIZE - 1 || surveyData[i] != surveyData[i + 1]) {

            if (currentFrequency > highestFrequency) {

                highestFrequency = currentFrequency;
                mostFrequent = surveyData[i];

            }

            currentFrequency = 0;

        }

    }

    cout << "Mode: " << mostFrequent << "\n";
    cout << mostFrequent << " appears " << highestFrequency << " times!\n";

}