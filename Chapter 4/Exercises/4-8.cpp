#include<iostream>

using std::cout;

struct listNode {
    char character;
    listNode * next;
};

typedef listNode * arrayString; // Will be used to reference the Linked List in itself!

// PREREQUISITES: string != NULL
void printString(arrayString & string) {

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

    // SPECIAL CASE: string only has a single node with char = 0
    if (loopPointer->next == NULL) {

        newNode->next = loopPointer;
        string = newNode;
        return;

    }

    // WHILE THE NEXT LISTNODE'S CHARACTER IS != 0 -- NEED THE SECOND-LAST NODE TO UPDATE ITS NEXT!
    while (loopPointer->next->character != 0)
        loopPointer = loopPointer->next;

    newNode->next = loopPointer->next;
    loopPointer->next = newNode;

}

// PREREQUISITES: s1 != NULL && s2 != NULL
void concatenate(arrayString & s1, arrayString s2) {

    listNode * s1LoopPointer = s1;
    listNode * s2LoopPointer = s2;

    // WHILE THE NEXT LISTNODE'S CHARACTER IS != 0 -- NEED THE SECOND-LAST NODE TO UPDATE ITS NEXT!
    while (s1LoopPointer->next->character != 0)
        s1LoopPointer = s1LoopPointer->next;

    listNode * finalNode = s1LoopPointer->next;
    listNode * previousNode = s1LoopPointer;

    while (s2LoopPointer->character != 0) {

        // NEW NODE
        listNode * newNode = new listNode;
        newNode->character = s2LoopPointer->character;

        // ADD TO LINKED LIST
        newNode->next = finalNode;
        previousNode->next = newNode;
        previousNode = newNode;

        // LOOP PROGRESSION
        s2LoopPointer = s2LoopPointer->next;

    }

}

void removeChars(arrayString & string, int start, int length) {

    listNode * loopPointer = string;
    int count = 1;

    // WHILE NOT AT THE NODE PREVIOUS TO THE NODE WHERE THE REMOVAL IS SUPPOSED TO START
    while (count < start - 1) {
        loopPointer = loopPointer->next; 
        count++;
    }

    listNode* removal;
    if (start == 1) {

        removal = loopPointer; // does not need 'count' adjustment because it avoids the previous loop

        while (count < start + length) {

            string = removal->next;
            delete removal;
            removal = string;
            count++;

        }

    }
    else {

        removal = loopPointer->next;
        count++; // needed to start at the correct position because the previous loop starts one node behind to adjust 'next' fields

        while (count < start + length) {

            loopPointer->next = removal->next;
            delete removal;
            removal = loopPointer->next;
            count++;

        }

    }

}

void freeRecords(arrayString & string) {

    listNode * loopPointer;

    while (string != NULL) {

        loopPointer = string;
        string = string->next;
        delete loopPointer;

    }

}

int main() {

    // First Linked List
    arrayString string1;

    // Data in first LinkedList
    listNode * node1 = new listNode;
    node1->character = 'm';
    listNode * node2 = new listNode;
    node2->character = 'y';
    listNode * node3 = new listNode;
    node3->character = 's';
    listNode * node4 = new listNode;
    node4->character = 't';
    listNode * node5 = new listNode;
    node5->character = 'e'; 
    listNode * node6 = new listNode;
    node6->character = 'r';
    listNode * node7 = new listNode;
    node7->character = 'y';
    listNode * node8 = new listNode;
    node8->character = 0; 
    

    // First LinkedList Setup
    string1 = node1; // Head Pointer
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = node8;
    node8->next = NULL;

    node1 = node2 = node3 = node4 = node5 = node6 = node7 = node8 = NULL;

    // OPERATIONS

    printString(string1);
    removeChars(string1, 5, 3);
    printString(string1);

    // Free Memory - LinkedList!
    freeRecords(string1);

}