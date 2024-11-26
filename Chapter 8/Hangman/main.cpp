#include <iostream>

using std::cin;
using std::cout;
using std::ios;

#include <fstream>

using std::ifstream;

#include <string>

using std::string;

#include <list>

using std::list;
using std::iterator;

#include <cstring>

list<string> readWordFile(const char * filename) {

    list<string> wordList;
    ifstream wordFile(filename, ios::in);

    if (wordFile.fail()) {
        cout << "File open failed. \n";
        return wordList;
    }

    char currentWord[30];
    while (wordFile >> currentWord) {
        if (strchr(currentWord, ('\'')) == 0) {
            string temp(currentWord); // Pretty sure this step is optional and you can directly use 'currentWord' without using a temporary field
            wordList.push_back(temp);
        }
    }

    return wordList;

}

void displayList(const list<string> & wordList) {

    list<string>::const_iterator iter;
    iter = wordList.begin();
    while (iter != wordList.end()) {
        cout << iter->c_str() << "\n";
        iter++;
    }

}

int countWordsWithoutLetter(const list<string> & wordList, char letter) {

    list<string>::const_iterator iter;
    int count = 0;
    iter = wordList.begin();

    while (iter != wordList.end()) {

        if (iter->find(letter) == string::npos) // 'string::npos' means that no matches were found
            count++;
        iter++;

    }

    return count;

}

void removeWordsOfWrongLength(list<string> & wordList, int acceptableLength) {

    list<string>::iterator iter;
    iter = wordList.begin();
    while (iter != wordList.end()) {

        if (iter->length() != acceptableLength)
            iter = wordList.erase(iter);
        else
            iter++;
    
    }

}

bool numberInPattern(const list<int> & pattern, int number) {

    list<int>::const_iterator iter;
    iter = pattern.begin();

    while (iter != pattern.end()) {

        if (*iter == number)
            return true;
        iter++;

    }

    return false;

}

bool matchesPattern(string word, char letter, list<int> pattern) {

    for (int i = 0; i < word.length(); i++) {

        if (word[i] == letter) {
            if (!numberInPattern(pattern, i))
                return false;
        }
        else 
            if (numberInPattern(pattern, i))
                return false;

    }

    return true;

}

void removeWordsWithoutLetter(list<string> & wordList, char requiredLetter) {

    list<string>::const_iterator iter;
    iter = wordList.begin();

    while (iter != wordList.end()) {

        if (iter->find(requiredLetter) == string::npos)
            iter = wordList.erase(iter);
        else
            iter++;

    }

}

void removeWordsWithLetter(list<string> & wordList, char forbiddenLetter) {

    list<string>::const_iterator iter;
    iter = wordList.begin();

    while (iter != wordList.end()) {

        if (iter->find(forbiddenLetter) != string::npos)
            iter = wordList.erase(iter);
        else
            iter++;

    }

}

void mostFreqPatternByLetter(list<string> wordList, char letter, list<int> & maxPattern, int & maxPatternCount) {

    removeWordsWithoutLetter(wordList, letter);

    list<string>::iterator iter;
    maxPatternCount = 0;

    while (wordList.size() > 0) {

        iter = wordList.begin();
        list<int> currentPattern;

        for (int i = 0; i < iter->length(); i++) 
            if ((*iter)[i] == letter)
                currentPattern.push_back(i);

        int currentPatternCount = 1;
        iter = wordList.erase(iter);

        while (iter != wordList.end()) {

            if (matchesPattern(*iter, letter, currentPattern)) {
                currentPatternCount++;
                iter = wordList.erase(iter);
            }
            else
                iter++;

        }

        if (currentPatternCount > maxPatternCount) {
            maxPatternCount++;
            maxPattern = currentPattern;
        }

        currentPattern.clear();

    }

}

list<string> reduceByPattern(list<string> & wordList, char letter, list<int> & pattern) {

    list<string>::const_iterator iter;
    iter = wordList.begin();

    list<string> reducedList;

    while (iter != wordList.end()) {

        if (matchesPattern(*iter, letter, pattern))
            reducedList.push_back(*iter);
        iter++;
        
    }

    return reducedList;

}

void displayGuessedLetters(bool letters[26]) {

    cout << "Letters guessed: ";

    for (int i = 0; i < 26; i++) 
        if (letters[i])
            cout << (char)('a' + i) << " ";

    cout << "\n";

}

int main() {

    const char * filename = "wordList.txt";
    list<string> wordList = readWordFile(filename);
    // displayList(wordList);

    const int wordLength = 8;
    const int maxMisses = 9;

    int misses = 0;
    int discoveredLetterCount = 0;

    removeWordsOfWrongLength(wordList, wordLength);

    char revealedWord[wordLength + 1] = "********";
    bool guessedLetters[26];
    for (int i = 0; i < 26; i++)
        guessedLetters[i] = false;

    char nextLetter;
    cout << "Word so far: " << revealedWord << "\n";

    while (discoveredLetterCount < wordLength && misses < maxMisses) {

        cout << "Letter to guess: ";
        cin >> nextLetter;
        
        guessedLetters[nextLetter - 'a'] = true;

        int missingCount = countWordsWithoutLetter(wordList, nextLetter);

        list<int> nextPattern;
        int nextPatternCount;

        mostFreqPatternByLetter(wordList, nextLetter, nextPattern, nextPatternCount);
        // IF THERE IS MORE OPTIONS BY CHOOSING WORDS WITHOUT THAT LETTER
        if (missingCount > nextPatternCount) {

            removeWordsWithLetter(wordList, nextLetter);
            misses++;

        }
        else {

            list<int>::iterator iter = nextPattern.begin();
            while (iter != nextPattern.end()) {

                discoveredLetterCount++;
                revealedWord[*iter] = nextLetter;
                iter++;

            }

            // ONLY WORDS WITH PATTERN CONTINUE
            wordList = reduceByPattern(wordList, nextLetter, nextPattern);

        }

        cout << "Word so far: " << revealedWord << "\n";
        displayGuessedLetters(guessedLetters);

    }

    if (misses == maxMisses) {

        cout << "Sorry. You lost. The word I was thinking of was '";
        cout << (wordList.cbegin()->c_str()) << "' .\n";

    }
    else 
        cout << "Great job. You win. Word was'" << revealedWord << "' .\n";

    return 0;

}