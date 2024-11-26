#include<iostream>

using std::cout;

struct listNode {
    int studentNum;
    int grade;
    listNode * next;
};

typedef listNode * studentCollection; // Will be used to reference the Linked List in itself!

void addRecord(studentCollection& sc, int stuNum, int gr) {

    // New Node Creation
    listNode * newNode = new listNode;
    newNode->studentNum = stuNum;
    newNode->grade = gr;

    // Adding Node to Linked List
    newNode->next = sc;
    sc = newNode;

}

double averageRecord(studentCollection sc) {

    if (sc == NULL)
        return 0;

    int count = 0;
    double sum = 0;
    listNode * loopPtr = sc;

    while (loopPtr != NULL) {

        sum += loopPtr->grade;
        count++;
        loopPtr = loopPtr->next;

    }

    double average = sum / count;
    return average;

}

void freeRecords(studentCollection& sc) {

    listNode * loopPointer;

    while (sc != NULL) {

        loopPointer = sc;
        sc = sc->next;
        delete loopPointer;

    }

    // sc = NULL; is not needed because the last iteration of cycle already does that

}

int main() {
    
    // Linked List
    studentCollection sc;
    
    // Data in LinkedList
    listNode * node1 = new listNode;
    node1->studentNum = 1001; node1->grade = 78;
    listNode * node2 = new listNode;
    node2->studentNum = 1012; node2->grade = 93;
    listNode * node3 = new listNode;
    node3->studentNum = 1076; node3->grade = 85;

    // LinkedList Setup
    sc = node1; // Head Pointer
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;
    node1 = node2 = node3 = NULL;

    // Perform Operations
    
    addRecord(sc, 1274, 91);
    int avg = averageRecord(sc);

    cout << "Grade Average: " << avg << "\n";

    // Free Memory - LinkedList!
    freeRecords(sc);

}