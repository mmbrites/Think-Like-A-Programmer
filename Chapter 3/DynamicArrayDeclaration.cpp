#include <iostream>
using std::cout;
using std::cin;

int main() {

    int ARRAY_SIZE;
    cout << "Number of survey responses: ";
    cin >> ARRAY_SIZE;
    int* surveyData = new int[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) {

        cout << "Survey response " << i + 1 << ": ";
        cin >> surveyData[i];

    }

}