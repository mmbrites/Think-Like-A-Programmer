#include <iostream>

using std::cout;

#include "Hangman.hpp"

Hangman::Hangman() { }

Hangman::Hangman(int maximumMisses, int wordLength) : _maximumMisses(maximumMisses), _wordLength(wordLength), _latestGuess(false), _misses(0) {

    initialiseWordToGuess();
    initialiseLetters();
    _wordDir.fillWordList();
    _wordDir.removeWords(_wordLength); // This could be optimised by filtering the words when fetching them from the file

}

int Hangman::maximumMisses() { return _maximumMisses; }
int Hangman::wordLength() { return _wordLength; }

string Hangman::wordToGuess() { return _wordToGuess; }
void Hangman::setWordToGuess(string word) { _wordToGuess = word; }

bool Hangman::latestGuess() { return _latestGuess; }
void Hangman::setLatestGuess(bool lGuess) { _latestGuess = lGuess; }

int Hangman::misses() { return _misses; }
void Hangman::incrementMisses() { _misses++; }

void Hangman::guess(char playerGuess) {

    int wordsWithoutLetter = _wordDir.countWordsWithoutLetter(playerGuess);
    list<int> mostFrequentPattern;
    int wordsWithLetter = _wordDir.countWordsWithMostFrequentPattern(mostFrequentPattern, playerGuess);

    if (wordsWithoutLetter < wordsWithLetter) {

        _wordDir.removeWordsWithoutLetter(playerGuess);
        _wordDir.removeWords(mostFrequentPattern, playerGuess);

        updateWordToGuess(mostFrequentPattern, playerGuess);

    }
    else
        _wordDir.removeWordsWithLetter(playerGuess);

    guessedLetter(playerGuess - 'a');

}

void Hangman::displayGuessedLetters() {

    cout << "Letters guessed: ";
    for (int i = 0; i < 26; i++)
        if (_letters[i])
            cout << (char) ('a' + i) << " ";

    cout << "\n";

}

void Hangman::guessedLetter(int position) {
    _letters[position] = true;
}

string Hangman::retrieveHiddenWord() {
    return _wordDir.wordList().front();
}

bool Hangman::checkGuessedLetter(char playerGuess) {
    return _letters[playerGuess - 'a'];
}

void Hangman::initialiseWordToGuess() {

    _wordToGuess = "*";
    for (int i = 1; i < _wordLength; i++)
        _wordToGuess += "*";

}

void Hangman::initialiseLetters() {

    for (int i = 0; i < 26; i++)
        _letters[i] = false;

}

void Hangman::updateWordToGuess(list<int> pattern, char letter) {

    list<int>::iterator it = pattern.begin();
    int words = 0;

    while (it != pattern.end())
        _wordToGuess[*it] = letter;

}