#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::vector;

#define END_OF_LINE_ASCII_CODE 10 // this 'code' can vary depending on the operating system, '10' works for Fedora Linux
#define SPACE 32

int compareFunc(const void* voidA, const void* voidB) {

    int * intA = (int *)(voidA);
    int * intB = (int *)(voidB);

    return *intA - *intB;

}

int main() {

    // Integer Array
    vector<int> array;
    array.reserve(10);

    cout << "Insert integers to fill array (separate integers with a 'space'): ";

    char digitChar = cin.get();
    int currentNumber = 0;
    bool negativeNumber = false;
    while (digitChar != END_OF_LINE_ASCII_CODE) {

        if (digitChar == '-') {
            negativeNumber = true;
            digitChar = cin.get();
            continue;
        }

        // Dealing with integer
        if (digitChar != SPACE)
            currentNumber = currentNumber * 10 + (digitChar - '0');
        else {

            if(negativeNumber) {
                currentNumber = -currentNumber;
                negativeNumber = false;
            }

            array.push_back(currentNumber);
            currentNumber = 0;
            
        }

        digitChar = cin.get();

    }

    if(negativeNumber)
        currentNumber = -currentNumber;

    // Needed for last number inputted!
    array.push_back(currentNumber);

    // Cannot use vector therefore I use the first element's address
    qsort(&array[0], array.size(), sizeof(int), compareFunc);

    int mostFrequent;
    int highestFrequency = 0;
    int currentFrequency = 0;

    for (int i = 0; i < array.size(); i++) {

        currentFrequency++;

        // if (surveyData[i] IS LAST OCCURENCE OF A VALUE)
        if (i == array.size() - 1 || array[i] != array[i + 1]) {

            if (currentFrequency > highestFrequency) {

                highestFrequency = currentFrequency;
                mostFrequent = array[i];

            }

            currentFrequency = 0;

        }

    }

    cout << "Mode: " << mostFrequent << "\n";
    cout << mostFrequent << " appears " << highestFrequency << " times!\n";

}