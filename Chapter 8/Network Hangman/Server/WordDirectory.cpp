#include <fstream>
#include <iostream>

using std::ifstream;
using std::cout;

#include "WordDirectory.hpp"

WordDirectory::WordDirectory() { }

list<string> WordDirectory::wordList() {
    return _wordList;
}

void WordDirectory::setWordList(list<string> wList) {
    _wordList = wList;
}

void WordDirectory::fillWordList() {

    ifstream wordListFile("wordList.txt");

    if (wordListFile.fail()) {
        cout << "File open failed. \n";
        return;
    }

    string word;
    while (wordListFile >> word)
        _wordList.push_back(word);

    wordListFile.close();

}

void WordDirectory::displayWordList() {

    for (string s : _wordList)
        cout << s << "\n";

}

int WordDirectory::countWordsWithoutLetter(char letter) {

    list<string>::iterator it = _wordList.begin();
    int words = 0;

    while (it != _wordList.end()) {

        if (containsLetter(*it, letter))
            words++;
            
        ++it;
    
    }

    return words;

}

int WordDirectory::countWordsWithMostFrequentPattern(list<int> & pattern, char letter) {

    int maximum = 0;
    list<string> wordListClone(_wordList);
    privateRemoveWordWithoutLetter(wordListClone, letter);

    while (wordListClone.size() > 0) {

        if (containsLetter(wordListClone.front(), letter)) {

            list<string>::iterator it = wordListClone.begin();
            list<int> currentPattern = createPattern(*it, letter);
            int patternFrequency = 0;
            while (it != wordListClone.end()) {

                if (containsPattern(*it, currentPattern, letter)) {

                    patternFrequency++;
                    it = wordListClone.erase(it);

                }
                else
                    ++it;
            
            }

            if (patternFrequency > maximum) {

                maximum = patternFrequency;
                pattern = currentPattern;

            }


            currentPattern.clear(); // unsure if I need this :|

        }

    }

    return maximum;

}

void WordDirectory::removeWords(int length) {

    list<string>::iterator it = _wordList.begin();

    while (it != _wordList.end()) {

        if ((*it).size() != length)
            it = _wordList.erase(it);
        else
            ++it;

    }

}

void WordDirectory::removeWordsWithLetter(char letter) {

    list<string>::iterator it = _wordList.begin();

    while (it != _wordList.end()) {

        if (containsLetter(*it, letter))
            it = _wordList.erase(it);
        else
            ++it;

    }

}

void WordDirectory::removeWordsWithoutLetter(char letter) {

    list<string>::iterator it = _wordList.begin();

    while (it != _wordList.end()) {

        if (!containsLetter(*it, letter))
            it = _wordList.erase(it);
        else
            ++it;

    }

}

void WordDirectory::removeWords(list<int> pattern, char letter) {

    list<string>::iterator it = _wordList.begin();

    while (it != _wordList.end()) {

        if (!containsPattern(*it, pattern, letter))
            it = _wordList.erase(it);
        else
            ++it;

    }

}

bool WordDirectory::containsLetter(string s, char letter) {

    for (int i = 0; i < s.size(); i++)
        if (s[i] == letter)
            return true;

    return false;

}

bool WordDirectory::containsPattern(string s, list<int> pattern, char letter) {    

    for (int i = 0; i < s.size(); i++) {

        if (s[i] == letter) {

            if (!positionInPattern(i, pattern)) {
                return false;
            }

        }
        else {

            if (positionInPattern(i, pattern))
                return false;

        }

    }

    return true;

}

list<int> WordDirectory::createPattern(string s, char letter) {

    list<int> pattern;

    for (int i = 0; i < s.size(); i++)
        if (s[i] == letter)
            pattern.push_back(i);

    return pattern;

}

bool WordDirectory::positionInPattern(int position, list<int> pattern) {

    list<int>::iterator it = pattern.begin();

    while (it != pattern.end()) {

        if (*it == position)
            return true;
        
        ++it;

    }    

    return false;

}

void WordDirectory::privateRemoveWordWithoutLetter(list<string> & cloneList, char letter) {

    list<string>::iterator it = cloneList.begin();

    while (it != cloneList.end()) {

        if (!containsLetter(*it, letter))
            it = cloneList.erase(it);
        else
            ++it;

    }

}