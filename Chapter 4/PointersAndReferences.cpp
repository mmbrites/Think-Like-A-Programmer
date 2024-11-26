#include<iostream>

int main() {

    int a = 3;
    int b = 4;

    // Pointer assignment is not transitive
    // The line p = pointerToB changes the value of p, i.e. it now points to a different piece of memory
    int* pointerToA = &a;
    int* pointerToB = &b;
    int* p = pointerToA;
    p = pointerToB;
    printf("%d %d %d\n", a, b, *p); // Prints 3 4 4

    // Reference assignment is transitive
    // r = referenceToB does something completely different: it assigns the value of b to where the value of a used to be. It does not change r at all. r is still a reference to the same piece of memory
    int& referenceToA = a;
    int& referenceToB = b;
    int& r = referenceToA;
    r = referenceToB;
    printf("%d %d %d\n", a, b, r); // Prints 4 4 4

}