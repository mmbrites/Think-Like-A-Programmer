#include <iostream>
#include <utility>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>

using std::cout;
using std::stack;
using std::queue;
using std::vector;
using std::sort;

#include "binaryTree.hpp"

// CONSTRUCTORS
binaryTree::binaryTree() {
    _root = nullptr;
}

binaryTree::binaryTree(const binaryTree & original) {
    _root = copiedTree(original._root);
}

binaryTree::binaryTree(binaryTree && original) {
    _root = original._root;
    original._root = nullptr;
}

// DESTRUCTOR
binaryTree::~binaryTree() {
    deleteTree(_root);
    _root = nullptr;
}

// OPERATOR OVERLOADS

// COPY ASSIGNMENT
binaryTree & binaryTree::operator=(const binaryTree & rhs) {

    if (this != &rhs) {

        deleteTree(_root);
        _root = copiedTree(rhs._root);

    }
    
    return *this;

}

// MOVE ASSIGNMENT
binaryTree & binaryTree::operator=(binaryTree && rhs) {

    std::swap(_root, rhs._root);
    return *this;

}

binaryTree::treePtr binaryTree::copiedTree(const binaryTreeNode * original) {

    if (original == nullptr)
        return nullptr;

    return copiedTree(original);

}

binaryTree::treePtr binaryTree::copiedTree(treePtr root) {

    if (root == nullptr)
        return nullptr;

    treePtr left = copiedTree(root->left);
    treePtr right = copiedTree(root->right);

    treePtr newNode = new binaryTreeNode;
    newNode->data = root->data;
    newNode->left = left;
    newNode->right = right;

    return newNode;

}

void binaryTree::deleteTree(treePtr node) {

    if (node == nullptr)
        return;
    
    deleteTree(node->left);
    deleteTree(node->right);

    delete node;

}

void binaryTree::addTreeNode(int newAddition) {

    if (_root == nullptr) {

        treePtr newNode = new binaryTreeNode;
        newNode->data = newAddition;
        newNode->left = nullptr;
        newNode->right = nullptr;
        _root = newNode;
        return;

    }

    // addTreeNode(newAddition, _root, nullptr);
    // heapAddTreeNode(newAddition, _root);
    balancedAddTreeNode(newAddition, _root, nullptr);

}

int binaryTree::publicLeafCount() {
    return privateLeafCount(_root);
}

int binaryTree::stackBasedLeafCount() {

    if(_root == nullptr)
        return 0;
    
    int leafCount = 0;
    stack<binaryTreeNode *> nodes;
    nodes.push(_root);

    while (!nodes.empty()) {

        treePtr currentNode = nodes.top();
        nodes.pop();
        if (currentNode->left == nullptr && currentNode->right == nullptr)
            leafCount++;
        else {
            if (currentNode->right != nullptr)
                nodes.push(currentNode->right);
            if (currentNode->left != nullptr)
                nodes.push(currentNode->left);
        }

    }

    return leafCount;

}

bool binaryTree::heapBinaryTree(treePtr rootPtr) {

    if (!completeTree(rootPtr))
        return false;
    return maxHeap(rootPtr, nullptr);

}

// PYRAMID IMPLEMENTATION - NODES ARE ONLY ADDED TO THE EXTREMES
void binaryTree::addTreeNode(int newAddition, treePtr currentNode, treePtr previousNode) {

    if (currentNode == nullptr) {

        treePtr newNode = new binaryTreeNode;
        newNode->data = newAddition;
        newNode->left = nullptr;
        newNode->right = nullptr;

        if (newAddition < 0)
            previousNode->left = newNode;
        else
            previousNode->right = newNode;

    }
    else {

        if (newAddition < 0)
            addTreeNode(newAddition, currentNode->left, currentNode);
        else
            addTreeNode(newAddition, currentNode->right, currentNode);

    }

}

// BALANCED IMPLEMENTATION - IF LOWER THAN PARENT -> LEFT; IF BIGGER OR EQUAL TO PARENT -> RIGHT
void binaryTree::balancedAddTreeNode(int newAddition, treePtr currentNode, treePtr previousNode) {

    if (currentNode == nullptr) {

        treePtr newNode = new binaryTreeNode;
        newNode->data = newAddition;
        newNode->left = nullptr;
        newNode->right = nullptr;

        if (newAddition < previousNode->data)
            previousNode->left = newNode;
        else
            previousNode->right = newNode;

    }
    else {

        if (newAddition < currentNode->data)
            balancedAddTreeNode(newAddition, currentNode->left, currentNode);
        else
            balancedAddTreeNode(newAddition, currentNode->right, currentNode);

    }

}

// HEAP ADD - IGNORES VALUES BIGGER THAN ROOT BECAUSE THIS TREE IS NOT EQUIPED WITH A WAY TO EASILY HANDLE TREE REBALANCING, I.E., THE STRUCT DEFINING THE BINARY WOULD NEED TO DEFINE A POINTER TO THE NODE'S PARENT
void binaryTree::heapAddTreeNode(int newAddition, treePtr currentNode) {

    if (currentNode->left == nullptr || currentNode->right == nullptr) {

        treePtr newNode = new binaryTreeNode;
        newNode->data = newAddition;
        newNode->left = nullptr;
        newNode->right = nullptr;

        if (currentNode->left == nullptr)
            currentNode->left = newNode;
        else
            currentNode->right = newNode;

    }
    else {

        // IF THE NODE CAN BE IN THE HEAP AND LEFT NODE HAS SPACE FOR CHILDREN
        if ((newAddition < currentNode->left->data) && ((currentNode->left->left == nullptr) || (currentNode->left->right == nullptr)))
            heapAddTreeNode(newAddition, currentNode->left);
        // IF THE NODE CAN BE IN THE HEAP AND RIGHT NODE HAS SPACE FOR CHILDREN
        else if ((newAddition < currentNode->right->data) && ((currentNode->right->left == nullptr) || (currentNode->right->right == nullptr)))
            heapAddTreeNode(newAddition, currentNode->right);

    }

}

binaryTree::treePtr binaryTree::getRoot() {
    return _root;
}

int binaryTree::privateLeafCount(treePtr rootPtr) {

    if (rootPtr == nullptr)
        return 0;

    if (rootPtr->right == nullptr && rootPtr->left == nullptr)
        return 1;

    int leftCount = privateLeafCount(rootPtr->left);
    int rightCount = privateLeafCount(rootPtr->right);

    return leftCount + rightCount;

}

bool binaryTree::completeTree(treePtr rootPtr) {

    if (rootPtr == nullptr)
        return false;

    queue<treePtr> treeNodes;
    treeNodes.push(rootPtr);
    bool foundNullNode = false;

    while (!treeNodes.empty()) {

        treePtr currentNode = treeNodes.front();
        treeNodes.pop();

        if (currentNode->left) {

            if (foundNullNode)
                return false;
            treeNodes.push(currentNode->left);

        }
        else
            foundNullNode = true;

        if (currentNode->right) {

            if (foundNullNode)
                return false;
            treeNodes.push(currentNode->right);

        }
        else
            foundNullNode = true;

    }
    return true;
}

int binaryTree::countChildren(treePtr node) {

    if (node->left == nullptr && node->right == nullptr)
        return 0;
    else if (node->left == nullptr || node->right == nullptr)
        return 1;
    else
        return 2;

}

bool binaryTree::maxHeap(treePtr rootPtr, treePtr parent) {

    if (countChildren(rootPtr) == 0)
        return true;
    if (countChildren(rootPtr) == 1) {
        if (rootPtr->left != nullptr)
            return rootPtr->data >= rootPtr->left->data;
        else
            return rootPtr->data >= rootPtr->right->data;
    }

    bool current;
    bool leftHeap = maxHeap(rootPtr->left, rootPtr);
    bool rightHeap = maxHeap(rootPtr->right, rootPtr);

    if (rootPtr == getRoot() || rootPtr->data <= parent->data)
        current = true;

    return current && leftHeap && rightHeap;

}

bool binaryTree::binarySearchTree(treePtr rootPtr) {

    if (rootPtr == nullptr)
        return false;

    return privateBinarySearchTree(rootPtr, nullptr, false);

}

bool binaryTree::privateBinarySearchTree(treePtr rootPtr, treePtr parent, bool left) {

    if (countChildren(rootPtr) == 0) {

        if (left) {

            if (rootPtr->data <= parent->data)
                return true;
            return false;

        }
        else {

            if (rootPtr->data >= parent->data)
                return true;
            return false;

        }
        
    }

    if (countChildren(rootPtr) == 1) {

        if (rootPtr->left != nullptr)
            return rootPtr->left->data <= rootPtr->data;
        else
            return rootPtr->right->data >= rootPtr->data;

    }

    bool leftTree = privateBinarySearchTree(rootPtr->left, rootPtr, true);
    bool rightTree = privateBinarySearchTree(rootPtr->right, rootPtr, false);

    bool current = true;
    if (rootPtr != _root) {
        if (left)
            if (rootPtr->data > parent->data)
                current = false;
        else
            if (rootPtr->data < parent->data)
                current = false;
        
    }

    return current && leftTree && rightTree;

}

int binaryTree::countNodes(treePtr rootPtr) {

    if (rootPtr == nullptr)
        return 0;

    int leftTreeNodes = countNodes(rootPtr->left);
    int rightTreeNodes = countNodes(rootPtr->right);
    return 1 + rightTreeNodes + leftTreeNodes;

}

double binaryTree::average(treePtr rootPtr) {

    if (rootPtr == nullptr)
        return 0;

    double leftTreeAverage = average(rootPtr->left);
    double rightTreeAverage = average(rootPtr->right);

    // OBVIAMENTE PODE SER OTIMIZADO E TORNAR COUNTNODES EM ALGO QUE NÃO PRECISE DE SER CHAMADO CONSTANTEMENT, E.G., ARGUMENTO DA FUNÇÃO
    double currentAverage = (double) rootPtr->data / countNodes(_root);

    return currentAverage + leftTreeAverage + rightTreeAverage;

}

vector<int> binaryTree::toVector(treePtr rootPtr) {

    if (rootPtr == nullptr) {
        return {};
    }

    vector<int> leftTreeNodes = toVector(rootPtr->left);
    vector<int> rightTreeNodes = toVector(rootPtr->right);

    vector<int> nodes;
    nodes.push_back(rootPtr->data);
    nodes.insert(nodes.end(), leftTreeNodes.begin(), leftTreeNodes.end());
    nodes.insert(nodes.end(), rightTreeNodes.begin(), rightTreeNodes.end());

    return nodes;

}

double binaryTree::median(treePtr rootPtr) {

    vector<int> nodes = toVector(rootPtr);
    sort(nodes.begin(), nodes.end(), [](int a, int b) { return a < b; });

    int middleArrayPosition = nodes.size() / 2;
    double median;
    if (nodes.size() % 2 == 0)
        median = (nodes.at(middleArrayPosition - 1) + nodes.at(middleArrayPosition)) / 2.0;
    else
        median = nodes.at(middleArrayPosition);

    return median;

}

int binaryTree::mode(treePtr rootPtr) {

    vector<int> nodes = toVector(rootPtr);
    sort(nodes.begin(), nodes.end(), [](int a, int b) { return a < b; });
    
    int mostFrequent;
    int highestFrequency = 0;
    int currentFrequency = 0;

    for (int i = 0; i < nodes.size(); i++) {

        currentFrequency++;

        // if (surveyData[i] IS LAST OCCURENCE OF A VALUE)
        if (i == nodes.size() - 1 || nodes.at(i) != nodes.at(i + 1)) {

            if (currentFrequency > highestFrequency) {

                highestFrequency = currentFrequency;
                mostFrequent = nodes.at(i);

            }

            currentFrequency = 0;

        }

    }

    return mostFrequent;

}