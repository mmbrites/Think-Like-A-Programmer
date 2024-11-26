#include <iostream>

using std::cout;

// More commonly used in C, allows NULL in pass by reference parameters
void compute(int input, int * output) { }

// In this function we are passing the argument by reference which allows us to change its value outside of the scope. It is not a copy! Only a pointer is created!
void refParamFunction(int &x) {
    cout << &x << "\n";
    x = 10;
}

// In this function we are also passing the argument by reference, but we are not changing it, just querying it. This can be useful to avoid wasting memory space since only a pointer is created!
int anotherFunction(const int &x) {

    if (x == 5)
        cout << "Not changed!\n";
    else if (x == 10)
        cout << "Changed!\n";

    return 0;

}

int main() {

    int number = 5;
    refParamFunction(number);
    cout << number << "\n";
    anotherFunction(number);

}