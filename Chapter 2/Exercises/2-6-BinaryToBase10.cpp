#include <iostream>
using std::cin;
using std::cout;

#define END_OF_LINE_ASCII_CODE 10 // this 'code' can vary depending on the operating system, '10' works for Fedora Linux

int main() {

    std::string numberToConvert;
    int originNumberBase = 2;
    int destinationNumberBase = 10;

    cout << "Convert number ";
    char digitChar = cin.get();

    do {

        numberToConvert += digitChar; // the 'append' function does not work on 'char'
        digitChar = cin.get();

    } while (digitChar != END_OF_LINE_ASCII_CODE);

    cout << numberToConvert << "\n";

    int result = 0;
    int currentDigit;

    if (numberToConvert.at(0) == '1') {

        int firstDigitWeight = -1;

        for (int i = 1; i < numberToConvert.size(); i++) {

            currentDigit = numberToConvert.at(i) -'0';
            firstDigitWeight = firstDigitWeight * 2;
            result = result * 2 + currentDigit;
        
        }

        cout << result << "\n";

        result += firstDigitWeight;

    }
    else {
 
        for (char digit : numberToConvert) {

            currentDigit = digit - '0';
            result = result * 2 + currentDigit;

        }
    
    }

    cout << result << "\n";

}