#include <iostream>

using std::cout;

#include "TreeNode.hpp"

int main() {

    // NODES DECLARATION
    TreeNode node1(9);
    TreeNode node2(18);
    TreeNode node3(16);
    TreeNode node4(8);
    TreeNode node5(27);
    TreeNode node6(23);

    // TREE CONSTRUCTION
    node1.addChild(&node3);
    node1.addChild(&node2);
    node1.addChild(&node5);
    node5.addChild(&node4);
    node5.addChild(&node6);

    cout << node1.leaves() << "\n";
    node2.debugSet();

}