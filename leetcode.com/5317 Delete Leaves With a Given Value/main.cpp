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
    bool delete_this(TreeNode *root, int target) {
        if (root->right && delete_this(root->right, target)) {
            // delete root->right;
            root->right = nullptr;
        }
        if (root->left && delete_this(root->left, target)) {
            // delete root->left;
            root->left = nullptr;
        }
        if (root->left == nullptr && root->right == nullptr && root->val == target) return true;
        return false;
    }
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (root && delete_this(root, target)) {
            // delete root;
            return nullptr;
        }
        return root;
    }
};