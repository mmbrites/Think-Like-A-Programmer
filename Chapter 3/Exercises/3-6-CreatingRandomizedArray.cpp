#include <iostream>
#include <random>
using std::cout;

bool alreadyInArray(int shift, char* cipher, int arraySize) {

    for (int i = 0; i < arraySize; i++)
        if (cipher[i] == ('A' + shift))
            return true;

    return false;

}

int main() {

    const int ARRAY_SIZE = 26;
    char cipher[ARRAY_SIZE] = {};

    // Create random number
    std::random_device seed;
    std::mt19937 gen{seed()}; // seed the generator
    std::uniform_int_distribution<> dist{0, 25}; // set min and max

    for (int i = 0; i < ARRAY_SIZE; i++) {

        int shift;

        do { 
            shift = dist(gen); // generate number 
        } while (i == shift || alreadyInArray(shift, cipher, ARRAY_SIZE));

        cipher[i] = ('A' + shift);

    }

    for (int i = 0; i < ARRAY_SIZE; i++)
        cout << cipher[i] << "\n";

}