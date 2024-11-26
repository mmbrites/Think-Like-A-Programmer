#include <set>

class TreeNode {

    public:
        TreeNode();
        TreeNode(int value);

        // GETTERS & SETTERS
        int value();

        // OPERATIONS
        void addChild(TreeNode * node);
        int leaves();
        void debugSet();

    private:
        std::set<TreeNode *> _children;
        int _value;

};