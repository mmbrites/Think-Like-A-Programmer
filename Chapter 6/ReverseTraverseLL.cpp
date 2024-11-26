#include <iostream>
#include <stack>

using std::cout;
using std::stack;

struct listNode {

    int data;
    listNode * next;

};

typedef listNode * listPtr;

void displayListForwardsRecursion(listPtr head) {

    if (head != nullptr) {

        cout << head->data << "\n";
        displayListForwardsRecursion(head->next);

    }

}

void displayListBackwardsRecursion(listPtr head) {

    if (head != nullptr) {

        displayListBackwardsRecursion(head->next);
        cout << head->data << "\n";

    }

}

void displayListForwardsIterative(listPtr head) {

    for (listPtr current = head; current != nullptr; current = current->next)
        cout << current->data << "\n";

}

void displayListBackwardsIterative(listPtr head) {

    stack<listPtr> nodes;
    for (listPtr current = head; current != nullptr; current = current->next)
        nodes.push(current);

    while (!nodes.empty()) {

        listPtr current = nodes.top();
        nodes.pop();
        cout << current->data << "\n";

    }

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
    node1->data = 4;
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

    cout << "Forwards Recursion:\n";
    displayListForwardsRecursion(head);

    cout << "Backwards Recursion:\n";
    displayListBackwardsRecursion(head);

    cout << "Forwards Iterative:\n";
    displayListForwardsIterative(head);

    cout << "Backwards Iterative:\n";
    displayListBackwardsIterative(head);

    freeRecords(head);    

}