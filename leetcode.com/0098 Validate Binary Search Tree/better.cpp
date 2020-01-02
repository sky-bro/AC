#include <iostream>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//  Inorder Traversal
class Solution {
private:
    bool _isValidBST(TreeNode* root, int &prev, bool &prev_bound) {
        if (root->left && !_isValidBST(root->left, prev, prev_bound)) return false;
        if (prev_bound && root->val <= prev) return false;
        prev = root->val;
        prev_bound = true;
        if (root->right && !_isValidBST(root->right, prev, prev_bound)) return false;
        return true;
    }
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        int prev = INT32_MIN;
        bool prev_bound = false;
        return _isValidBST(root, prev, prev_bound);
    }
};
