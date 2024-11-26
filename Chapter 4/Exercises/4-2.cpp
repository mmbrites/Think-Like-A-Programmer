#include<iostream>

using std::cout;

typedef char * arrayString;

// PREREQUISITES: string != NULL && start >= 1 && length >= 1
arrayString substring(arrayString string, int start, int length) {

    arrayString result = new char[length];

    for (int i = start - 1, j = 0; i <= start - 1 + length - 1; i++, j++)
        result[j] = string[i];

    return result;

}

void substringTester() {

    arrayString string = new char[7];
    string[0] = 'a'; string[1] = 'b'; string[2] = 'c'; string[3] = 'd'; string[4] = 'e'; string[5] = 'f'; string[6] = 'g';

    arrayString result = substring(string, 3, 4);

    cout << result << "\n";

    delete[] string;
    delete[] result;
    string = NULL;
    result = NULL;

}

int main() {
    substringTester();
}