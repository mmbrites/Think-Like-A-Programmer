#include <iostream>

using std::cout;

#include "TreeNode.hpp"

TreeNode::TreeNode() {
    _value = 0;
}

TreeNode::TreeNode(int value) {
    _value = value;
}

int TreeNode::value() {
    return _value;
}

void TreeNode::addChild(TreeNode * node) {
    _children.insert(node);
}

int TreeNode::leaves() {

    if (_children.empty())
        return 1;

    int count = 0;

    // Traverse all the children of the current node
    for (std::set<TreeNode *>::iterator it = _children.begin(); it != _children.end(); ++it)
        count += (*it)->leaves();

    return count;

}

void TreeNode::debugSet() {

    for (std::set<TreeNode *>::iterator it = _children.begin(); it != _children.end(); ++it)
        cout << (*it)->value() << "\n";

}