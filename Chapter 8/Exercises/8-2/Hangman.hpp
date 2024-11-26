#include <string>

using std::string;

#include "WordDirectory.hpp"

class Hangman {

    public:
        Hangman();
        Hangman(int maximumMisses, int wordLength);

        // GETTERS & SETTERS
        int maximumMisses(); // I PREFER THAT BOTH OF THESE FIELDS ARE OBTAINED VIA THIS CHANNEL ('SERVER-SIDE') INSTEAD OF USING THE FIELDS DEFINED IN 'MAIN'
        int wordLength();

        string wordToGuess();
        void setWordToGuess(string word);

        bool latestGuess();
        void setLatestGuess(bool lGuess);

        int misses();
        void incrementMisses();

        // OPERATIONS
        void guess(char playerGuess); // Main function of the game
        void displayGuessedLetters(); // Displays the letters that have been guessed
        void guessedLetter(int position); // Updates _letters
        string retrieveHiddenWord(); // Chooses a winning word to 'satisfy' the challenger
        bool checkGuessedLetter(char playerGuess);

    private:
        // Both values are actually defined by the user, therefore they are initialised in a member initialiser list
        const int _maximumMisses = 0;
        const int _wordLength = 0;

        string _wordToGuess;
        bool _latestGuess;
        int _misses;

        WordDirectory _wordDir;

        bool _letters[26];

        // AUXILIAR OPERATIONS
        void initialiseWordToGuess();
        void initialiseLetters();
        void updateWordToGuess(list<int> pattern, char letter); // Updates the word to show to the user
        
};