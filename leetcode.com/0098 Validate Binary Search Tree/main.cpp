#include <iostream>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    bool _isValidBST(TreeNode* root, int left, int right, bool left_bound, bool right_bound) {
        if ( left_bound && root->val <= left || right_bound && root->val >= right) return false;
        if (root->right && !_isValidBST(root->right, root->val, right, true, right_bound)) return false;
        if (root->left && !_isValidBST(root->left, left, root->val, left_bound, true)) return false;
        return true;
    }
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        return _isValidBST(root, INT32_MIN, INT32_MAX, false, false);
    }
};
