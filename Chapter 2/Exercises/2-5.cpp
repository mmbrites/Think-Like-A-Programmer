#include <iostream>
using std::cin;
using std::cout;

// Since the book has already done an explanation on how to verify an identification number using the Luhn formula, in this case, this program generates the check digit for an identification number using the ISBN formula.

#define END_OF_LINE_ASCII_CODE 10 // this 'code' can vary depending on the operating system, '10' works for Fedora Linux
#define WEIGHT_IN_ODD_POSITIONS 1
#define WEIGHT_IN_EVEN_POSITIONS 3
#define IDENTIFICATION_NUMBER_LENGTH 12

int main() {

    char digit;
    int checksum = 0;
    int position = 1;

    cout << "Enter an ISBN identification number (" << IDENTIFICATION_NUMBER_LENGTH << " digits): ";
    digit = cin.get();

    while (digit != END_OF_LINE_ASCII_CODE) {

        if(digit == '-') {

            digit = cin.get();
            continue;
        
        }

        if (position % 2 == 0)
            checksum += (digit - '0') * WEIGHT_IN_EVEN_POSITIONS;
        else
            checksum += (digit - '0') * WEIGHT_IN_ODD_POSITIONS;

        digit = cin.get();
        position++;

    }
    
    cout << "The check digit of the provided ISBN identification number is " << checksum % 10 << "\n";

}