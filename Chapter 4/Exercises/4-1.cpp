#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::vector;

#define SURVEY_DATA_INITIAL_LENGTH 5

// Finding the mode :)

void resizeSurveyData(int * & surveyData, int& surveyDataLength) {

    int * newArray = new int[surveyDataLength * 2];

    for (int i = 0; i < surveyDataLength; i++)
        newArray[i] = surveyData[i];

    delete[] surveyData;

    surveyData = newArray;
    surveyDataLength *= 2;

    newArray = NULL;
    
}

int main() {

    int * surveyData = new int[SURVEY_DATA_INITIAL_LENGTH];
    int surveyDataLength = SURVEY_DATA_INITIAL_LENGTH;
    int surveyDataSamples = 0;

    int surveyResponse;
    cout << "Enter next survey response or -1 to end: ";
    cin >> surveyResponse;

    while (surveyResponse != -1) {
        
        if (surveyDataSamples == surveyDataLength)
            resizeSurveyData(surveyData, surveyDataLength);

        surveyData[surveyDataSamples++] = surveyResponse;
        cout << "Enter next survey response or -1 to end: ";
        cin >> surveyResponse;
    
    }

    int arraySize = surveyDataSamples;
    const int MAX_RESPONSE = 10;
    int histogram[MAX_RESPONSE];

    for (int i = 0; i < MAX_RESPONSE; i++)
        histogram[i] = 0;

    for (int i = 0; i < arraySize; i++)
        histogram[surveyData[i] - 1]++;

    int mostFrequent = 0;
    for (int i = 1; i < MAX_RESPONSE; i++)
        if (histogram[i] > histogram[mostFrequent])
            mostFrequent = i;

    mostFrequent++; 

    cout << "Mode: " << mostFrequent << "\n";
    cout << mostFrequent << " appears " << histogram[mostFrequent - 1] << " times!\n";

    delete[] surveyData;
    surveyData = NULL;

}