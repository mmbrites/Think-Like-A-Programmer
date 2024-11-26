#include<iostream>

using std::cout;

struct listNode {
    int digit;
    listNode * next;
};

typedef listNode * numberAsList; // Will be used to reference the Linked List in itself!

// PREREQUISITES: 
int length(int integer) {

    int length = 0;

    if (integer == 0)
        return 1;

    while (integer != 0) {
        integer /= 10;
        length++;
    }
    return length;

}

// PREREQUISITES: number == NULL && integer >= 0 && integer <= 2147483647
void intToList(numberAsList & number, int integer) {

    int dividedNumber = integer;
    int count = 1;

    while (count <= length(integer)) {

        // NODE CREATION
        listNode * node = new listNode;
        node->digit = dividedNumber % 10;
        node->next = number;
        number = node;
        
        dividedNumber /= 10;
        count++;

    }

}

// PREREQUISITES: none
void printNumber(numberAsList & number) {

    listNode * loopPointer = number;
    while (loopPointer != NULL) {
            
        cout << loopPointer->digit;
        loopPointer = loopPointer->next;

    }

    cout << "\n";

}

// PREREQUISITES: none
void freeRecords(numberAsList & number) {

    listNode * loopPointer;

    while (number != NULL) {

        loopPointer = number;
        number = number->next;
        delete loopPointer;

    }

}

int main() {

    // Needs to be initiliazed as NULL due to the intToList method
    numberAsList number = NULL;
    
    intToList(number, 21394);
    printNumber(number);
    
    freeRecords(number);

}