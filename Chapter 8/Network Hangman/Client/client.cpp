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

// Creates and connects the client socket with the server socket. @returns client socket file descriptor
int setupClientSocket() {

    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    if (clientSocket < 0) {

        perror("Cannot create socket!\n");
        exit(0);

    }

    struct sockaddr_in serverSocketAddress;
    const int SERVER_PORT = 8080;
    const string SERVER_IP = "192.168.68.111";
    serverSocketAddress.sin_family = AF_INET;
    serverSocketAddress.sin_addr.s_addr  = inet_addr(SERVER_IP.c_str());
    serverSocketAddress.sin_port = htons(SERVER_PORT);

    if (connect(clientSocket, (struct sockaddr *) &serverSocketAddress, sizeof(serverSocketAddress)) < 0) {

        perror("Connection failed...");
        exit(0);

    }

    return clientSocket;

}

// Sends a message to the server via the client socket file descriptor. @params client socket file descriptor & message to send
void sendMessageToServer(int clientSocket, string message) {

    int messageStatus = send(clientSocket, message.c_str(), message.size(), 0);

    if (messageStatus < 0) {

        perror("Error while sending the message...");
        exit(0);
    
    }

}

// Receives a message from the server via the client socket file descriptor. @params client socket file descriptor & buffer to fill & buffer's size
void receiveMessageFromServer(int clientSocket, char receiveBuffer[], int size) {

    int messageStatus = recv(clientSocket, receiveBuffer, size, 0);

    if (messageStatus < 0) {

        perror("Error while reading from socket!");
        exit(0);
    
    }

}

// Receives a welcome message to the game sent by the server via the client socket file descriptor. @param client socket file descriptor
void receiveWelcome(int clientSocket) {

    char buffer[1024] = {0};
    receiveMessageFromServer(clientSocket, buffer, 1024);
    cout << buffer;

}

// Receives a request by the server to set a game parameter and sends the answer. @param client socket file descriptor
void setGameParameter(int clientSocket) {

    char buffer[1024] = {0};
    receiveMessageFromServer(clientSocket, buffer, 1024);
    cout << buffer;

    string message;
    cin >> message;
    sendMessageToServer(clientSocket, message);

}

int main() {

    int clientSocket = setupClientSocket();

    receiveWelcome(clientSocket);

    setGameParameter(clientSocket); // 'maximumMisses'
    setGameParameter(clientSocket); // 'wordLength'

    close(clientSocket);

}