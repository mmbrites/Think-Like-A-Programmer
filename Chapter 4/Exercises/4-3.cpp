#include<iostream>

using std::cout;

typedef char * arrayString;

int length(arrayString s) {

    int count = 0;
    while (s[count] != 0)
        count++;
    return count;

}

// PREREQUISITES: string != NULL && position >= 0
void removePattern(arrayString & string, int position, int patternLength) {

    arrayString newSource = new char[length(string) - patternLength];

    for (int i = 0; i < position; i++)
        newSource[i] = string[i];

    for (int i = position + patternLength; i < length(string); i++)
        newSource[i - patternLength] = string[i];
    
    delete[] string;
    string = newSource;
    newSource = NULL;

}

// PREREQUISITES: string != NULL && pattern != NULL && position >= 0
void addPattern(arrayString & string, arrayString pattern, int position) {

    arrayString newSource = new char[length(string) + length(pattern)];

    for (int i = 0; i < position; i++)
        newSource[i] = string[i];

    for (int i = position, j = 0; i < position + length(pattern); i++, j++)
        newSource[i] = pattern[j];

    for (int i = position; i < length(string); i++)
        newSource[i + length(pattern)] = string[i];

    delete[] string;
    string = newSource;
    newSource = NULL;

} 

// PREREQUISITES: source != NULL && target != NULL && replaceText != NULL
void replaceText(arrayString & source, arrayString target, arrayString textReplacement) {

    for (int i = 0; i < length(source); i++) {

        // TARGET IDENTIFICATION
        if (source[i] == target[0]) {

            bool foundTarget = true;
            for (int j = 1; j < length(target); j++)
                if (source[i + j] != target[j])
                    foundTarget = false;

            // TARGET REPLACEMENT
            if (foundTarget) {

                // TARGET REMOVAL
                removePattern(source, i, length(target));

                // REPLACETEXT ADDITION
                addPattern(source, textReplacement, i);

                // COMPENSATION FOR TEXT REPLACEMENT TO EVADE SPECIAL CASE WHERE TARGET IS INSIDE TEXTREPLACEMENT E.G., TARGET = "AB" && TARGETREPLACEMENT = "ABAB"
                i += length(textReplacement) - 1;

            }

        }

    }

}

void replaceTextTester() {

    arrayString source = new char[2];
    source[0] = 'a'; source[1] = 'b'; source[2] = 'c'; source[3] = 'd'; source[4] = 'a'; source[5] = 'b'; source[6] = 'e'; source[7] = 'e';

    arrayString target = new char[2];
    target[0] = 'a'; target[1] = 'b';

    arrayString textReplacement = new char[4];
    textReplacement[0] = 'a'; textReplacement[1] = 'b'; textReplacement[2] = 'a'; textReplacement[3] = 'b';

    replaceText(source, target, textReplacement);

    cout << source << "\n";

    delete[] source;
    delete[] target;
    delete[] textReplacement;
    source = NULL;
    target = NULL;
    textReplacement = NULL;

}

int main() {
    replaceTextTester();
}