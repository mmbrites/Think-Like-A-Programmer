#include <iostream>

using std::cout;

struct listNode {

    int data;
    listNode * next;

};

typedef listNode * listPtr;

listPtr compareTriplets(listPtr a, listPtr b) {

    if (a == nullptr || b == nullptr) {

        listPtr node1 = new listNode;
        listPtr node2 = new listNode;
        node1->next = node2;
        node2->next = nullptr;
        return node1;
    
    }

    listPtr head = compareTriplets(a->next, b->next);
    if(a->data > b->data)
        head->data += 1;
    else if (a->data < b->data)
        head->next->data += 1;

    return head;

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

    // ALICE LIST
    listPtr alice;
    listNode * node1 = new listNode;
    node1->data = 2;
    listNode * node2 = new listNode;
    node2->data = 0;
    listNode * node3 = new listNode;
    node3->data = 1;

    alice = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = nullptr;

    // BOB LIST
    listPtr bob;
    node1 = new listNode;
    node1->data = 3;
    node2 = new listNode;
    node2->data = 2;
    node3 = new listNode;
    node3->data = 0;

    bob = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = nullptr;

    node1 = node2 = node3 = nullptr;

    listPtr results = compareTriplets(alice, bob);

    for (listPtr current = results; current != nullptr; current = current->next)
        cout << current->data << "\n";
    
    freeRecords(alice);
    freeRecords(bob);
    freeRecords(results);

}