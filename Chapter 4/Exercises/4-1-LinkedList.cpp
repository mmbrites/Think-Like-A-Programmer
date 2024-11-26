#include <iostream>
#include <vector>

using std::cout;
using std::vector;

// Compare Triplets Problem from Hacker Rank, but this time instead of triplets, we can add more data from Alice and Bob and thus, compare more data

struct listNode {
    int score;
    listNode * next;
};

typedef listNode * userScores;

void fillAliceScore(userScores& alice) {

    listNode * node1 = new listNode;
    node1->score = 0;
    listNode * node2 = new listNode;
    node2->score = 1;
    listNode * node3 = new listNode;
    node3->score = 2;

    alice = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;
    node1 = node2 = node3 = NULL;

}

void fillBobScore(userScores& bob) {

    listNode * node1 = new listNode;
    node1->score = 2;
    listNode * node2 = new listNode;
    node2->score = 0;
    listNode * node3 = new listNode;
    node3->score = 1;

    bob = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;
    node1 = node2 = node3 = NULL;

}

vector<int> compareTriplets(userScores alice, userScores bob) {
    
    vector<int> results;
    results.reserve(2);
    
    results.push_back(0);
    results.push_back(0);

    listNode * aliceLoopPointer = alice;
    listNode * bobLoopPointer = bob;

    while (aliceLoopPointer != NULL && bobLoopPointer != NULL) {

        int aliceScore = aliceLoopPointer->score;
        int bobScore = bobLoopPointer->score;

        if (aliceScore > bobScore)
            results[0]++;
        else if (aliceScore < bobScore)
            results[1]++;

        aliceLoopPointer = aliceLoopPointer->next;
        bobLoopPointer = bobLoopPointer->next;

    }

    return results;

}

void freeLinkedList(userScores& structure) {

    listNode * loopPointer;

    while (structure != NULL) {

        loopPointer = structure;
        structure = structure->next;
        delete loopPointer;

    }

}

int main() {

    userScores alice;
    userScores bob;

    fillAliceScore(alice);
    fillBobScore(bob);

    vector<int> result = compareTriplets(alice, bob);

    for (int i : result)
        cout << i << "\n";

    freeLinkedList(alice);
    freeLinkedList(bob);

}