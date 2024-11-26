#include <iostream>
using std::cin;
using std::cout;

#define END_OF_LINE_ASCII_CODE 10 // this 'code' can vary depending on the operating system, '10' works for Fedora Linux

int hexadecimalToDecimal(std::string numberToConvert) {

    int result = 0;
    int currentDigit;

    for (char digit : numberToConvert) {

        if (digit >= '0' && digit <= '9')
            currentDigit = digit - '0';
        else 
            currentDigit = digit - 'A' + 10;

        
        result = result * 16 + currentDigit;

    }

    return result;

}

int main() {

    std::string numberToConvert;
    int originNumberBase = 10;
    int destinationNumberBase = 2;

    cout << "Convert number ";
    char digitChar = cin.get();

    do {

        numberToConvert += digitChar; // the 'append' function does not work on 'char'
        digitChar = cin.get();

    } while (digitChar != END_OF_LINE_ASCII_CODE);

    int resultInDecimal = 0;

    if (numberToConvert.at(0) == '-') {

        // NEGATIVE NUMBER

        resultInDecimal = - hexadecimalToDecimal(numberToConvert.substr(1, numberToConvert.size() - 1));

    }
    else {

        // POSITIVE NUMBER

        resultInDecimal = hexadecimalToDecimal(numberToConvert);
    
    }

    cout << resultInDecimal << "\n";

}