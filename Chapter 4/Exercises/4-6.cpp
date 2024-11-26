#include<iostream>

using std::cout;

struct listNode {
    char character;
    listNode * next;
};

typedef listNode * arrayString; // Will be used to reference the Linked List in itself!

// PREREQUISITES: string != NULL
void printString(arrayString string) {

    listNode * loopPointer = string;
    while (loopPointer != NULL) {

        cout << loopPointer->character;
        loopPointer = loopPointer->next;

    }

    cout << "\n";

}

// PREREQUISITES: string != NULL
int length(arrayString string) {

    listNode * loopPointer = string;
    int length = 0;
    while (loopPointer->character != 0) {

        length++;
        loopPointer = loopPointer->next;

    }

    return length;

}

// PREREQUISITES: string != NULL && position >= 0 && position < length(string)
char characterAt(arrayString string, int position) {

    int currentPosition = 0;

    listNode * loopPointer = string;

    while (loopPointer != NULL) {

        if (currentPosition == position)
            return loopPointer->character;

        currentPosition++;
        loopPointer = loopPointer->next;

    }

    return -1;

}

// PREREQUISITES: string != NULL && c != NULL
void append(arrayString & string, char c) {

    listNode * newNode = new listNode;
    newNode->character = c;

    listNode * loopPointer = string;

    // WHILE THE NEXT LISTNODE'S CHARACTER IS != 0 -- NEED THE SECOND-LAST NODE TO UPDATE ITS NEXT!
    while (loopPointer->next->character != 0)
        loopPointer = loopPointer->next;

    newNode->next = loopPointer->next;
    loopPointer->next = newNode;

}

void freeRecords(arrayString string) {

    listNode * loopPointer;

    while (string != NULL) {

        loopPointer = string;
        string = string->next;
        delete loopPointer;

    }

}

int main() {

    // Linked List
    arrayString string;

    // Data in LinkedList
    listNode * node1 = new listNode;
    node1->character = 't';
    listNode * node2 = new listNode;
    node2->character = 'e';
    listNode * node3 = new listNode;
    node3->character = 's';
    listNode * node4 = new listNode;
    node4->character = 't';
    listNode * node5 = new listNode;
    node5->character = 0; // I am following the idea of the exercise in Chapter 4, however this 0 does not serve any kind of purpose and removing it would make the code of the implemented operations more clear!

    // LinkedList Setup
    string = node1; // Head Pointer
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = NULL;

    node1 = node2 = node3 = node4 = node5 = NULL;

    // OPERATIONS

    printString(string);
    cout << length(string) << "\n";
    cout << characterAt(string, 2) << "\n";
    append(string, '!');
    cout << length(string) << "\n";
    printString(string);

    // Free Memory - LinkedList!
    freeRecords(string);

}