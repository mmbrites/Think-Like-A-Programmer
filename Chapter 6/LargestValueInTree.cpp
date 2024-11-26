#include <iostream>

using std::cout;

struct treeNode {

    int data;
    treeNode * left;
    treeNode * right;

};

typedef treeNode * treePtr;

int maxValue(treePtr root) {

    if (root == NULL) // Only happens if maxValue() is initially called with an empty tree as parameter
        return 0;

    if (root->right == NULL && root->left == NULL)
        return root->data;

    int leftMax = maxValue(root->left);
    int rightMax = maxValue(root->right);

    int maxNum = root->data;
    if (leftMax > maxNum)
        maxNum = leftMax;
    if (rightMax > maxNum)
        maxNum = rightMax;

    return maxNum;

}

void freeRecords(treePtr & head) {

    if (head == NULL)
        return;

    freeRecords(head->left);
    freeRecords(head->right);
    delete head;
    head = NULL;

}

int main() {

    treePtr head;
    treeNode * node1 = new treeNode;
    node1->data = 4;
    treeNode * node2 = new treeNode;
    node2->data = -3;
    treeNode * node3 = new treeNode;
    node3->data = 1;
    treeNode * node4 = new treeNode;
    node4->data = 10;

    head = node1;
    node1->left = node2;
    node1->right = node3;
    node2->left = NULL;
    node2->right = NULL;
    node3->left = node4;
    node3->right = NULL;
    node4->left = NULL;
    node4->right = NULL;

    node1 = node2 = node3 = node4 = NULL;

    cout << maxValue(head) << "\n";

    freeRecords(head);

}