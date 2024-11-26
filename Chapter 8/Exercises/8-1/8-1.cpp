#include <iostream>

using std::cout;
using std::cin;

#include "Hangman.hpp"

int main() {

    int maximumMisses, wordLength;

    cout << "Hello Challenger!\n";
    cout << "Please specify the game's paramaters.\n";
    
    cout << "Maximum misses: ";
    cin >> maximumMisses;

    cout << "Word Length: ";
    cin >> wordLength;

    Hangman game(maximumMisses, wordLength);
    cout << "Game started!\n";

    cout << "Word to guess: " << game.wordToGuess() << "\n";

    // FETCH SERVER-SIDE information
    while (game.misses() < game.maximumMisses()) {

        cout << "Insert your guess: ";

        char playerGuess;
        cin >> playerGuess;

        if (game.checkGuessedLetter(playerGuess)) {
            cout << "Your guess is invalid! You have already guessed this letter. Choose another :)\n";
            continue;
        }
        if (playerGuess >= 'A' && playerGuess <= 'Z')
            playerGuess += 32; // Transform character into lowercase
        else if (!(playerGuess >= 'a' && playerGuess <= 'z')) {
            cout << "Invalid guess! The current word database only has words with letters.\n";
            continue;
        }

        game.guess(playerGuess);

        if (game.latestGuess()) {

            cout << "Your guess was correct!\n";
            cout << "The word has been updated: " << game.wordToGuess() << "\n";

        }
        else {

            game.incrementMisses();
            cout << "Your guess was incorrect...\n";
            cout << "The word remains: " << game.wordToGuess() << "\n";

        }

        game.displayGuessedLetters();
        cout << "You have " << game.maximumMisses() - game.misses() << " chances to spare!\n";

    }

    if (game.misses() == game.maximumMisses()) {
        cout << "You lost. The word I was thinking of was obviouslyyyy '";
        cout << game.retrieveHiddenWord().c_str() << "'.\n";
    }
    else
        cout << "Oh... You won. The word was " << game.wordToGuess() << "\n";

}