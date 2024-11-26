#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::vector;

#define END_OF_LINE_ASCII_CODE 10 // this 'code' can vary depending on the operating system, '10' works for Fedora Linux
#define SPACE 32

void sortVector(vector<int> *array) {

    int start = 0;
    int end = (*array).size() - 1;

    for (int i = 1; i <= end; i++) {
        for (int j = i; j > start && (*array).at(j) < (*array).at(j - 1); j--) {

            int temporary = (*array)[j - 1];
            (*array)[j - 1] = (*array)[j];
            (*array)[j] = temporary;

        }
    }

}

double medianCalculator(vector<int> array) {

    int middleArrayPosition = array.size() / 2;
    if (array.size() % 2 == 0)
        return (array[middleArrayPosition - 1] + array[middleArrayPosition]) / 2.0;
    else
        return array[middleArrayPosition];

}

void quartileCalculation(double* firstQuartile, double* secondQuartile, double* thirdQuartile, vector<int> array) {

    // MEDIAN
    *secondQuartile = medianCalculator(array);

    // FIRST QUARTILE
    // Create subvector
    vector<int>::const_iterator first = array.begin();
    vector<int>::const_iterator last = array.begin() + array.size() / 2;
    vector<int> newVecFQ(first, last);
    *firstQuartile = medianCalculator(newVecFQ);

    // THIRD QUARTILE
    vector<int>::const_iterator firstTQ;
    vector<int>::const_iterator lastTQ;
    if (array.size() % 2 == 0) {
        firstTQ = array.begin() + array.size() / 2;
        lastTQ = array.begin() + array.size();
    }
    else {
        firstTQ = array.begin() + array.size() / 2 + 1;
        lastTQ = array.begin() + array.size();
    }
    vector<int> newVecTQ(firstTQ, lastTQ);
    *thirdQuartile = medianCalculator(newVecTQ);

}

int main() {

    // Integer Array
    vector<int> array;
    array.reserve(10);

    cout << "Insert grades (separate which integer with a 'space' and insert '-1' to finish input): ";

    int currentNumber;
    cin >> currentNumber;
    while (currentNumber != -1) {

        array.push_back(currentNumber);
        cin >> currentNumber;
    
    }

    sortVector(&array);

    vector<int>::iterator iterator;
    for (iterator = array.begin(); iterator != array.end(); iterator++)
        cout << *iterator << " ";

    cout << "\n";

    double firstQuartile;
    double secondQuartile;
    double thirdQuartile;

    switch (array.size()) {

        case 0:
            cout << "You have not provided any grades!\n";
            exit(-1);
            break;

        case 1:
            firstQuartile = secondQuartile = thirdQuartile = array[0];
            break;

        case 2:
            firstQuartile = array[0];
            secondQuartile = (array[0] + array[1]) / 2.0;
            thirdQuartile = array[1];
            break;

        case 3:
            firstQuartile = array[0];
            secondQuartile = array[1];
            thirdQuartile = array[2];
            break;

        default:
            quartileCalculation(&firstQuartile, &secondQuartile, &thirdQuartile, array);
            break;

    }

    cout << "1st Quartile: " << firstQuartile << "\n";
    cout << "2nd Quartile: " << secondQuartile << "\n";
    cout << "3rd Quartile: " << thirdQuartile << "\n";

}