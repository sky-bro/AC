#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct Node
{
    bool add_sons;
    TreeNode *parent;
    Node(TreeNode *_parent, bool _add_sons): parent(_parent), add_sons(_add_sons) {}
};


class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
        if (!root) return 0;
        int result;
        queue<Node> q;
        q.push(Node(root, false));
        while (!q.empty()) {
            Node node = q.front(); q.pop();
            bool add_sons = true;
            if (node.parent->val & 1) {
                add_sons = false;
            }
            
            if (node.parent->left) {
                if (node.add_sons) result += node.parent->left->val;
                q.push(Node(node.parent->left, add_sons));
            }
            if (node.parent->right) {
                if (node.add_sons) result += node.parent->right->val;
                q.push(Node(node.parent->right, add_sons));
            }
        }
        return result;
    }
};