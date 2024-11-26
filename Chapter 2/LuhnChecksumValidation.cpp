#include <iostream>
using std::cin;
using std::cout;

#define DOUBLE_DIGIT_THRESHOLD 10
#define END_OF_LINE_ASCII_CODE 10 // this 'code' can vary depending on the operating system, '10' works for Fedora Linux

int doubleDigitValue (int digit) {

    int doubleDigit = digit * 2;
    int digitSum;

    if (doubleDigit > DOUBLE_DIGIT_THRESHOLD) // pretty sure it is supposed to be ">=" due to 5 * 2 being a two-digit number
        digitSum = 1 + doubleDigit % 10;
    else
        digitSum = doubleDigit;

    return digitSum;

}

int main() {

    char digit;
    int oddLengthChecksum = 0;
    int evenLengthChecksum = 0;
    int position = 1;

    cout << "Enter a number: ";
    digit = cin.get();

    while (digit != END_OF_LINE_ASCII_CODE) {

        if (position % 2 == 0) {
            oddLengthChecksum += doubleDigitValue(digit - '0');
            evenLengthChecksum += digit - '0';
        }
        else {
            oddLengthChecksum += digit - '0';
            evenLengthChecksum += doubleDigitValue(digit - '0');
        }
        
        digit = cin.get();
        position++;

    }

    int checksum;

    // Since 'position' is updated at the end of the loop, it includes the positions of the 'end of line' character
    if ((position - 1) % 2 == 0)
        checksum = evenLengthChecksum;
    else
        checksum = oddLengthChecksum;

    cout << "Checksum is " << checksum << ". \n";
    if (checksum % 10 == 0)
        cout << "Checksum is divisible by 10. Valid. \n";
    else
        cout << "Checksum is not divisible by 10. Invalid. \n";

}