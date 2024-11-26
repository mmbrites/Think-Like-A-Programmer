#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h> // Needed to access structures used for internet domain addresses
#include <unistd.h> // Needed to close socket
#include <arpa/inet.h> // To access inet_addr()
#include <cstring>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::stoi;

#include "Hangman.hpp"

// Creates, binds and listens for a connection. @returns the server socket's file descriptor
int setupServerSocket() {

    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0) {

        perror("Cannot create socket!");
        exit(0);

    }

    struct sockaddr_in serverSocketAddress;
    const int PORT = 8080;

    serverSocketAddress.sin_family = AF_INET;
    serverSocketAddress.sin_addr.s_addr = inet_addr("192.168.68.111"); // serverSocketAddress.sin_addr.s_addr = INADDR_ANY;
    serverSocketAddress.sin_port = htons(PORT);

    if (bind(serverSocket, (struct sockaddr *) &serverSocketAddress, sizeof(serverSocketAddress)) < 0) {

        perror("Socket binding failed!");
        exit(0);

    }

    cout << "Waiting for player to join...\n";

    listen(serverSocket, 5);

    return serverSocket;

}

// Obtains the client socket file descriptor. @param server socket file descriptor. @returns client socket file descriptor
int setupClientSocket(int serverSocket) {

    int clientSocket = accept(serverSocket, nullptr, nullptr); 
    if (clientSocket < 0) {

        perror("Error on accept!");
        exit(0);

    }

    cout << "Player joined!\n";
    cout << "Game is starting...\n";

    return clientSocket;

}

// Sends a message to the client via the client socket file descriptor. @params client socket file descriptor & message to send
void sendMessageToClient(int clientSocket, string message) {

    int messageStatus = send(clientSocket, message.c_str(), message.size(), 0);

    if (messageStatus < 0) {

        perror("Error while sending the message...");
        exit(0);
    
    }

}

// Receives a message from the client via the client socket file descriptor. @params client socket file descriptor & buffer to fill & buffer's size
void receiveMessageFromClient(int clientSocket, char receiveBuffer[], int size) {

    int messageStatus = recv(clientSocket, receiveBuffer, size, 0);

    if (messageStatus < 0) {

        perror("Error while reading from socket!");
        exit(0);
    
    }

}

// Sends a welcome message to the client. @param client socket file descriptor
void welcomingMessage(int clientSocket) {

    string message = "Hello Challenger!\nPlease specify the game's parameters.\n";
    sendMessageToClient(clientSocket, message);

}

// Requests and obtains the 'maximum misses', which is necessary to start the Hangman game. @param client socket file descriptor. @returns the number of maximum misses
int requestMaximumMisses(int clientSocket) {

    string message = "Maximum misses: ";
    sendMessageToClient(clientSocket, message);

    char receiveBuffer[1024] = {0};
    receiveMessageFromClient(clientSocket, receiveBuffer, 1024);
    return stoi(receiveBuffer);

}

// Requests and obtains the 'word length', which is necessary to start the Hangman game. @param client socket file descriptor. @returns word length
int requestWordLength(int clientSocket) {

    string message = "Word Length: ";
    sendMessageToClient(clientSocket, message);

    char receiveBuffer[1024] = {0};
    receiveMessageFromClient(clientSocket, receiveBuffer, 1024);
    return stoi(receiveBuffer);

}

int main() {

    int serverSocket = setupServerSocket();
    int clientSocket = setupClientSocket(serverSocket);

    welcomingMessage(clientSocket);

    int maximumMisses = requestMaximumMisses(clientSocket);
    int wordLength = requestWordLength(clientSocket);

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

    close(clientSocket);
    close(serverSocket);

}