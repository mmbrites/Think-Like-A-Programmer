#include <iostream>
using std::cin;
using std::cout;

#define END_OF_LINE_ASCII_CODE 10 // this 'code' can vary depending on the operating system, '10' works for Fedora Linux
#define SPACE 32
#define HYPHEN 45


bool punctuation(char character) {
    return (character >= 33 && character <= 47 && character != HYPHEN) || (character >= 58 && character <= 64);
}

bool letter(char character) {
    return (character >= 'A' && character <= 'Z') || (character >= 'a' && character <= 'z');
}

bool vowel(char character) {
    return character == 'A' || character == 'a' || character == 'E' || character == 'e' || character == 'I' || character == 'i' || character == 'O' || character == 'o' || character == 'U' || character == 'u';
}

int main() {

    // Both fields are needed to correctly count the number of words
    char previousCharacter;
    char currentCharacter;

    // READ LINE AND CALCULATE STATISTICS

    // STATISTICS
    int numberOfWords = 0;
    int longestWord = 0;
    std::string longestWordString {};
    int greatestNumberOfVowelsInAWord = 0;
    std::string greatestNumberOfVowelsInAWordString {};
    int numberOfVowels = 0;
    int numberOfConsonants = 0;
    int numberOfPunctuationMarks = 0;

    // HELPERS
    int currentWordLength = 0;
    int currentNumberOfVowelsInWord = 0;
    std::string currentWord {};

    cout << "Write a line of text: ";

    previousCharacter = cin.get();
    if (previousCharacter != END_OF_LINE_ASCII_CODE) {

        do {

            currentCharacter = cin.get();

            if (letter(previousCharacter) && (currentCharacter == END_OF_LINE_ASCII_CODE || currentCharacter == SPACE 
            || punctuation(currentCharacter))) {
                
                numberOfWords++;
                currentWordLength++;
                currentWord += previousCharacter;

                if (currentWordLength > longestWord) {

                    longestWord = currentWordLength;
                    longestWordString = currentWord;
                
                }

                currentWordLength = 0;

                if (vowel(previousCharacter)) {
                    currentNumberOfVowelsInWord++;
                    numberOfVowels++;
                }
                else
                    numberOfConsonants++;

                if (currentNumberOfVowelsInWord > greatestNumberOfVowelsInAWord) {

                    greatestNumberOfVowelsInAWord = currentNumberOfVowelsInWord;
                    greatestNumberOfVowelsInAWordString = currentWord;
                
                }

                currentNumberOfVowelsInWord = 0;

                currentWord = {};

            }
            else if (letter(previousCharacter) && (letter(currentCharacter) || currentCharacter == HYPHEN)) {

                currentWordLength++;

                if (vowel(previousCharacter)) {

                    currentNumberOfVowelsInWord++;
                    numberOfVowels++;
                
                }
                else
                    numberOfConsonants++;

                currentWord += previousCharacter;
            
            }

            if (punctuation(previousCharacter) || previousCharacter == HYPHEN)
                numberOfPunctuationMarks++;

            previousCharacter = currentCharacter;

        } while (currentCharacter != END_OF_LINE_ASCII_CODE);

    }

    // OUTPUT STATISTICS

    cout << "Statistics:\n";
    cout << "\tNumber of words: " << numberOfWords << "\n";
    cout << "\tNumber of letters in the longest word: " << longestWord << "\n";
    cout << "\tLongest word: " << longestWordString << "\n";
    cout << "\tGreatest number of vowels in a word: " << greatestNumberOfVowelsInAWord << "\n";
    cout << "\tWord with the greatest number of vowels: " << greatestNumberOfVowelsInAWordString << "\n";
    cout << "\tNumber of vowels in line of text: " << numberOfVowels << "\n";
    cout << "\tNumber of consonants in line of text: " << numberOfConsonants << "\n";
    cout << "\tNumber of punctuation marks in line of text: " << numberOfPunctuationMarks << "\n";

}