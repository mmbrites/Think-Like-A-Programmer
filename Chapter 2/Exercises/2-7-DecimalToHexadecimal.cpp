#include <iostream>
using std::cin;
using std::cout;

#define END_OF_LINE_ASCII_CODE 10 // this 'code' can vary depending on the operating system, '10' works for Fedora Linux

std::string decimalToHexadecimal(int consecutiveDivisionsIntermediateResults) {

    std::string intermediateResult;
    std::string result;

    do {

        int currentModulo = consecutiveDivisionsIntermediateResults % 16;

        if (currentModulo < 10)
            intermediateResult += currentModulo + '0';
        else
            intermediateResult += currentModulo + '7';

        consecutiveDivisionsIntermediateResults /= 16;

    } while (consecutiveDivisionsIntermediateResults != 0);

    for (int i = intermediateResult.size() - 1; i >= 0; i--)
        result += intermediateResult.at(i);

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

    std::string result {};
    std::string intermediateResult {}; // Needed because the resulting binary number comes in 'reverse'

    int numberToConvertInteger = std::stoi(numberToConvert);

    if (numberToConvert.at(0) == '-')
        result = '-';
    
    result += decimalToHexadecimal(abs(numberToConvertInteger));
    cout << result << "\n";

}