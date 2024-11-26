#include <iostream>

using std::cout;

struct listNode {

    int data;
    listNode * next;

};

typedef listNode * listPtr;

int numberOfOccurrences(listPtr head, int target) {

    if (head == nullptr)
        return 0;

    int occurrences = numberOfOccurrences(head->next, target);
    if (head->data == target)
        occurrences++;

    return occurrences;

}

void freeRecords(listPtr & head) {

    listNode * loopPointer;

    while (head != NULL) {

        loopPointer = head;
        head = head->next;
        delete loopPointer;

    }

}

int main() {

    listPtr head;
    listNode * node1 = new listNode;
    node1->data = 1;
    listNode * node2 = new listNode;
    node2->data = -3;
    listNode * node3 = new listNode;
    node3->data = 1;
    listNode * node4 = new listNode;
    node4->data = -10;

    head = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = NULL;

    node1 = node2 = node3 = node4 = NULL;

    cout << numberOfOccurrences(head, 1) << "\n";
    
    freeRecords(head);    

}