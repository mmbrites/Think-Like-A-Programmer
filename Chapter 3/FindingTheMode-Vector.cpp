#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::vector;

int main() {

    vector<int> surveyData;
    surveyData.reserve(30);
    
    int surveyResponse;
    cout << "Enter next survey response or -1 to end: ";
    cin >> surveyResponse;

    while (surveyResponse != -1) {

        surveyData.push_back(surveyResponse);
        cout << "Enter next survey response or -1 to end: ";
        cin >> surveyResponse;
    
    }

    int vectorSize = surveyData.size();
    const int MAX_RESPONSE = 10;
    int histogram[MAX_RESPONSE];

    for (int i = 0; i < MAX_RESPONSE; i++)
        histogram[i] = 0;

    for (int i = 0; i < vectorSize; i++)
        histogram[surveyData[i] - 1]++;

    int mostFrequent = 0;
    for (int i = 1; i < MAX_RESPONSE; i++)
        if (histogram[i] > histogram[mostFrequent])
            mostFrequent = i;

    mostFrequent++; 

    cout << "Mode: " << mostFrequent << "\n";
    cout << mostFrequent << " appears " << histogram[mostFrequent - 1] << " times!\n";

}