#include <iostream>

using std::cout;

struct listNode {

    int data;
    listNode * next;

};

typedef listNode * listPtr;

bool oddOnesParity(listPtr & head) {

    if (head == nullptr)
        return false;

    bool odd = oddOnesParity(head->next);
    if (head->data == 1)
        odd = !odd;

    return odd;

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
    node2->data = 0;
    listNode * node3 = new listNode;
    node3->data = 1;
    listNode * node4 = new listNode;
    node4->data = 1;

    head = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = NULL;

    node1 = node2 = node3 = node4 = NULL;

    cout << oddOnesParity(head) << "\n";
    
    freeRecords(head);    

}