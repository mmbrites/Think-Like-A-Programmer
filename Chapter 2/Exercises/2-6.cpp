#include <iostream>
using std::cin;
using std::cout;

#define END_OF_LINE_ASCII_CODE 10 // this 'code' can vary depending on the operating system, '10' works for Fedora Linux

bool isPowerOf2(int x) { return x > 0 && !(x & (x - 1)); }

std::string base10tobase2(std::string numberToConvert, int isPowerOf2) {

    int numberToConvertInteger = 0;
    std::string result;
    int currentDigit;

    for (char digit : numberToConvert) {

        currentDigit = digit - '0';
        numberToConvertInteger = numberToConvertInteger * 10 + currentDigit;

    }

    int consecutiveDivisionsIntermediateResults = numberToConvertInteger;

    if (isPowerOf2 == 0)
        result += '0';

    std::string intermediateResult {}; // Needed because the resulting binary number comes in 'reverse'

    do {

        intermediateResult += (consecutiveDivisionsIntermediateResults % 2 + '0');
        consecutiveDivisionsIntermediateResults /= 2;

    } while (consecutiveDivisionsIntermediateResults != 0);

    // Invert 'intermediateResult' and append to 'result'
    for (int i = intermediateResult.size() - 1; i >= 0; i--)
        result += intermediateResult.at(i);

    return result;

}

std::string invertBits(std::string positiveResult) {

    std::string inversePositiveResult;

    for (int i = 0; i < positiveResult.size(); i++) {

        if (positiveResult.at(i) == '0')
            inversePositiveResult += '1';
        else
            inversePositiveResult += '0';

    }

    return inversePositiveResult;

}

std::string add1InBinary(std::string inversePositiveResult) {

    std::string intermediateResult;
    std::string result;

    for (int i = inversePositiveResult.size() - 1; i >= 0; i--) {

        if (inversePositiveResult.at(i) == '0') {
            intermediateResult += '1';

            for (int j = i - 1; j >= 0; j--)
                intermediateResult += inversePositiveResult.at(j);

            break;
        }
        else
            intermediateResult += '0';

    }

    // Invert 'intermediateResult' and append to 'result'
    for (int i = intermediateResult.size() - 1; i >= 0; i--)
        result += intermediateResult.at(i);

    return result;

}

int main() {

    std::string numberToConvert;
    int originNumberBase;
    int destinationNumberBase;

    cout << "Convert number ";
    char digitChar = cin.get();

    do {

        numberToConvert += digitChar; // the 'append' function does not work on 'char'
        digitChar = cin.get();

    } while (digitChar != END_OF_LINE_ASCII_CODE);

    cout << numberToConvert << "\n";

    cout << "   From base ";
    cin >> originNumberBase;
    
    cout << "   To base ";
    cin >> destinationNumberBase;

    std::string result {};

    if (originNumberBase == 10) {

        // DECIMAL TO BINARY

        if (numberToConvert.at(0) == '-') {

            // NEGATIVE NUMBER

            int number = abs(std::stoi(numberToConvert));

            // The second argument is needed to avoid problems in the first representatives of a new bit size, e.g., '10', '100', '1000', ...
            std::string positiveResult = base10tobase2(numberToConvert.substr(1, numberToConvert.size() - 1), isPowerOf2(number));
            std::string inversePositiveResult = invertBits(positiveResult);
            result = add1InBinary(inversePositiveResult);

        }
        else // POSITIVE NUMBER
            result = base10tobase2(numberToConvert, 0);

       

    }
    else {

        int resultInDecimal = 0;
        int currentDigit;

        if (numberToConvert.at(0) == '1') {

            // NEGATIVE NUMBER

            int firstDigitWeight = -1;

            for (int i = 1; i < numberToConvert.size(); i++) {

                currentDigit = numberToConvert.at(i) -'0';
                firstDigitWeight = firstDigitWeight * 2;
                resultInDecimal = resultInDecimal * 2 + currentDigit;
            
            }

            resultInDecimal += firstDigitWeight;

        }
        else {
    
            // POSITIVE NUMBER

            for (char digit : numberToConvert) {

                currentDigit = digit - '0';
                resultInDecimal = resultInDecimal * 2 + currentDigit;

            }
        
        }

        result = std::to_string(resultInDecimal);

    }

    cout << "Result: " << result << "\n";

}