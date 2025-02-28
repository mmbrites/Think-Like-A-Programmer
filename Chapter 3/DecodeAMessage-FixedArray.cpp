#include <iostream>
using std::cin;
using std::cout;

#define END_OF_LINE_ASCII_CODE 10 // this 'code' can vary depending on the operating system, '10' works for Fedora Linux
#define COMMA_ASCII_CODE 44

#define UPPERCASE_MODE_MODULO 27
#define LOWERCASE_MODE_MODULO 27
#define PUNCTUATION_MODE_MODULO 9

int main() {

    cout << "Enter a number with as many digits as you like: ";

    char outputCharacter;
    enum modeType {UPPERCASE, LOWERCASE, PUNCTUATION};
    modeType mode = UPPERCASE;

    const char punctuation[8] = {'!', '?', ',', '.', ' ', ';', '"', '\''};

    char digitChar;

    do {
    
        digitChar = cin.get();

        int number = digitChar - '0';
        digitChar = cin.get();

        while (digitChar != END_OF_LINE_ASCII_CODE && digitChar != COMMA_ASCII_CODE) {

            number = number * 10 + (digitChar - '0');
            digitChar = cin.get();

        }

        switch (mode) {

            case UPPERCASE:
                number = number % UPPERCASE_MODE_MODULO;
                outputCharacter = number + 'A' - 1;
                if (number == 0) {
                    mode = LOWERCASE;
                    continue;
                }
                break;
            
            case LOWERCASE:
                number = number % LOWERCASE_MODE_MODULO;
                outputCharacter = number + 'a' - 1;
                if (number == 0) {
                    mode = PUNCTUATION;
                    continue;
                }
                break;

            case PUNCTUATION:
                punctuation[number - 1];
                break;

        }

        cout << outputCharacter;

    } while (digitChar != END_OF_LINE_ASCII_CODE);

    cout << "\n";

}