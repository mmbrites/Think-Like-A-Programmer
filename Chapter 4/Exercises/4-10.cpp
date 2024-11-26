#include<iostream>

using std::cout;

struct listNode {
    int digit;
    listNode * next;
};

typedef listNode * numberAsList; // Will be used to reference the Linked List in itself!

// PREREQUISITES: integer >= 0 && integer <= 2147483647
int length(int integer) {

    int length = 0;

    // SPECIAL CASE if integer == '0' length is 1; without this case, length(0) would yield 0
    if (integer == 0)
        return 1;

    while (integer != 0) {
        integer /= 10;
        length++;
    }
    return length;

}

// PREREQUISITES: number == NULL && integer >= 0 && integer <= 2147483647
numberAsList intToList(int integer) {

    numberAsList number = NULL;

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

    return number;

}

// PREREQUISITES: number != NULL
int listToInt(numberAsList number) {

    listNode * loopPointer = number;
    int numberAsInteger = 0;
    while (loopPointer != NULL) {

        numberAsInteger = numberAsInteger * 10 + loopPointer->digit;
        loopPointer = loopPointer->next;

    }

    return numberAsInteger;

}

// PREREQUISITES: firstNumber != NULL && secondNumber != NULL
numberAsList listSum(numberAsList firstNumber, numberAsList secondNumber) {

    int sum = listToInt(firstNumber) + listToInt(secondNumber);
    return intToList(sum);

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
    
    numberAsList firstNumber = intToList(200);
    numberAsList secondNumber = intToList(56);
    printNumber(firstNumber);
    printNumber(secondNumber);

    numberAsList sum = listSum(firstNumber, secondNumber);
    printNumber(sum);
    
    freeRecords(firstNumber);
    freeRecords(secondNumber);
    freeRecords(sum);

}