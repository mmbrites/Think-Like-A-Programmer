// THIS CLASS WAS BUILT FOR TESTING PURPOSES, DO NOT TAKE IT THAT SERIOUSLY :)
#include <vector>

using std::vector;

class binaryTree {

    private:
        struct binaryTreeNode {
            int data;
            binaryTreeNode * left;
            binaryTreeNode * right;
        };
        typedef binaryTreeNode * treePtr;
        treePtr _root;

    public:
        binaryTree();
        binaryTree(const binaryTree & original);
        binaryTree(binaryTree && original);
        ~binaryTree();
        binaryTree & operator=(const binaryTree & rhs);
        binaryTree & operator=(binaryTree && rhs);
        int publicLeafCount();
        int stackBasedLeafCount();
        void addTreeNode(int newAddition);
        treePtr getRoot();
        bool completeTree(treePtr rootPtr);
        bool heapBinaryTree(treePtr rootPtr);
        bool binarySearchTree(treePtr rootPtr);
        double average(treePtr rootPtr);
        double median(treePtr rootPtr);
        int mode(treePtr rootPtr);

    private:
        treePtr copiedTree(const binaryTreeNode * original);
        treePtr copiedTree(treePtr root);
        void deleteTree(treePtr node);
        void addTreeNode(int newAddition, treePtr currentNode, treePtr previousNode);
        void balancedAddTreeNode(int newAddition, treePtr currentNode, treePtr previousNode);
        void heapAddTreeNode(int newAddition, treePtr currentNode);
        int privateLeafCount(treePtr rootPtr);
        int countChildren(treePtr node);
        bool maxHeap(treePtr rootPtr, treePtr parent);
        bool privateBinarySearchTree(treePtr rootPtr, treePtr parent, bool left);
        int countNodes(treePtr rootPtr);
        vector<int> toVector(treePtr rootPtr);

};