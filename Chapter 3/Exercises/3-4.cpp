#include <iostream>
#include <string>
using std::cout;
using std::cin;

#define END_OF_LINE_ASCII_CODE 10 // this 'code' can vary depending on the operating system, '10' works for Fedora Linux

int main() {

    const int ARRAY_SIZE = 26;
    const char cipher[ARRAY_SIZE] = {'X', 'N', 'B', 'Z', 'M', 'V', 'P', 'C', 'O', 'R', 'H', 'Q', 'Y', 'I', 'S', 'J', 'E', 'G', 'T', 'U', 'L', 'K', 'D', 'F', 'W', 'A'};

    std::string ciphertext {};

    cout << "Insert plaintext: ";

    char digitChar = cin.get();
    while (digitChar != END_OF_LINE_ASCII_CODE) {

        if (digitChar >= 'A' && digitChar <= 'Z')
            ciphertext += cipher[digitChar - 'A'];
        else
            ciphertext += digitChar;
        digitChar = cin.get();

    }

    cout << "Ciphertext: " << ciphertext << "\n";

}