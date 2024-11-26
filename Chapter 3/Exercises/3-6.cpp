#include <iostream>
#include <string>
#include <random>
using std::cout;
using std::cin;

#define END_OF_LINE_ASCII_CODE 10 // this 'code' can vary depending on the operating system, '10' works for Fedora Linux

int findArrayPosition(char character, int arraySize, const char* cipher) {

    for (int i = 0; i < arraySize; i++)
        if (character == cipher[i])
            return i;

    return -1;

}

bool alreadyInArray(int shift, char* cipher, int arraySize) {

    for (int i = 0; i < arraySize; i++)
        if (cipher[i] == ('A' + shift))
            return true;

    return false;

}

int main() {

    const int ARRAY_SIZE = 26;
    char cipher[ARRAY_SIZE] = {};

    std::string ciphertext {};
    std::string plaintext {};

    // Create random number
    std::random_device seed;
    std::mt19937 gen{seed()}; // seed the generator - MT19937 is an algorithm
    std::uniform_int_distribution<> dist{0, 25}; // set min and max - uniform int distribution produces integer values evenly distributed across a range

    for (int i = 0; i < ARRAY_SIZE; i++) {

        int shift;

        do { 
            shift = dist(gen); // generate number 
        } while (i == shift || alreadyInArray(shift, cipher, ARRAY_SIZE));

        cipher[i] = ('A' + shift);

    }

    cout << "Current cipher: ";

    for (int i = 0; i < ARRAY_SIZE; i++)
        cout << cipher[i] << " ";

    cout << "\nInsert plaintext: ";

    char digitChar = cin.get();
    while (digitChar != END_OF_LINE_ASCII_CODE) {

        if (digitChar >= 'A' && digitChar <= 'Z')
            ciphertext += cipher[digitChar - 'A'];
        else
            ciphertext += digitChar;
        digitChar = cin.get();

    }

    cout << "Ciphertext: " << ciphertext << "\n";

    for (int i = 0; i < ciphertext.size(); i++) {

        char currentCharacter = ciphertext.at(i);
        int shift;

        if (currentCharacter >= 'A' && currentCharacter <= 'Z') {
            shift = findArrayPosition(currentCharacter, ARRAY_SIZE, cipher);
            plaintext += ('A' + shift);
        }
        else
            plaintext += currentCharacter;
              
    }

    cout << "Plaintext: " << plaintext << "\n";

}