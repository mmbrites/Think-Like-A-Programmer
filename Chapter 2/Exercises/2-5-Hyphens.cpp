#include <iostream>
using std::cin;
using std::cout;

int main() {

    char digit;

    cout << "Enter a number: ";
    digit = cin.get();

    while (digit != '\n') {

        if(digit == '-') {
            digit = cin.get();
            continue;
        }

        cout << digit;
        digit = cin.get();

    }

    cout << "\n";

}