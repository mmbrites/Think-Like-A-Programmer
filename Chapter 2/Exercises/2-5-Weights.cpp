#include <iostream>
using std::cin;
using std::cout;

#define WEIGHT_IN_ODD_POSITIONS 1
#define WEIGHT_IN_EVEN_POSITIONS 3
#define IDENTIFICATION_NUMBER_LENGTH 12

int main() {

    char digit;
    int checksum = 0;
    int position = 1;

    cout << "Enter an ISBN identification number (" << IDENTIFICATION_NUMBER_LENGTH << " digits): ";
    digit = cin.get();

    while (digit != '\n') {

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
        cout << checksum << "\n";

    }
    
    cout << checksum;
    cout << "\n";

}