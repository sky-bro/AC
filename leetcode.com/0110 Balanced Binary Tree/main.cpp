#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    bool balanced;
    bool _isBalanced(TreeNode* root, int &height) {
        int left_height = 0, right_height = 0;
        if (!balanced) return false;
        if (root->left && !_isBalanced(root->left, left_height)) return false;
        if (root->right && !_isBalanced(root->right, right_height)) return false;
        height = max(left_height, right_height) + 1;
        if (left_height - right_height < 2 && left_height - right_height > -2) return true;
        return false;
    }
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        balanced = true;
        int height = 0;
        return _isBalanced(root, height);
    }
};