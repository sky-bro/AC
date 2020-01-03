#include <iostream>
#include <vector>

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
    bool _isSymmetric(TreeNode* left, TreeNode* right) {
        if (left == right) return true;
        else if (!left || !right) return false;
        if (left->val != right->val) return false;
        if (!_isSymmetric(left->right, right->left)) return false;
        if (!_isSymmetric(left->left, right->right)) return false;
        return true;
    }
public:
    bool isSymmetric(TreeNode* root) {
        if (root) return _isSymmetric(root->left, root->right);
        return true;
    }
};
