#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        TreeNode tree(0); tree.right = root;
        TreeNode* pre_node = &tree;
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode* cur_node = stk.top(); stk.pop();
            pre_node->right = cur_node;
            pre_node = cur_node;
            if (cur_node->right) {
                stk.push(cur_node->right);
                // cur_node->right = nullptr;
            }
            if (cur_node->left) {
                stk.push(cur_node->left);
                cur_node->left = nullptr;
            }
        }
    }
};