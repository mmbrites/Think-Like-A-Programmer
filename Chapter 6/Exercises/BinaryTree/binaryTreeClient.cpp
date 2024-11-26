#include <iostream>

using std::cout;

#include "binaryTree.hpp"

int main() {

    binaryTree b;

    b.addTreeNode(57);
    b.addTreeNode(38);
    b.addTreeNode(53);
    b.addTreeNode(9);
    b.addTreeNode(7);

    /*cout << b.getRoot()->data << "\n";
    cout << b.getRoot()->left->data << "\n";
    cout << b.getRoot()->left->right->data << "\n";
    cout << b.getRoot()->left->left->data << "\n";
    cout << b.getRoot()->left->left->left->data << "\n";*/

    // FOR PYRAMID BINARY TREE
    /*cout << b.getRoot()->data << "\n";
    cout << b.getRoot()->right->data << "\n";
    cout << b.getRoot()->right->right->data << "\n";
    cout << b.getRoot()->right->right->right->right->data << "\n";
    cout << b.getRoot()->right->right->right->right->data << "\n";*/

    binaryTree b1(b);

    binaryTree b2;
    b2 = b1;

    // FOR HEAP BINARY TREE
    /*cout << b2.getRoot()->data << "\n";
    cout << b2.getRoot()->left->data << "\n";
    cout << b2.getRoot()->right->data << "\n";
    cout << b2.getRoot()->left->left->data << "\n";
    cout << b2.getRoot()->left->right->data << "\n";*/
    
    cout << b2.mode(b2.getRoot()) << "\n";

}