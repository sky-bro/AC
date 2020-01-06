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
    int sum;
    bool _hasPathSum(TreeNode* root, int &path_sum) {
        if (root->left == nullptr && root->right == nullptr) {
            if (path_sum == sum) return true;
            return false;
        }
        if (root->left) {
            path_sum += root->left->val;
            if (_hasPathSum(root->left, path_sum)) return true;
            path_sum -= root->left->val;
        }
        if (root->right) {
            path_sum += root->right->val;
            if (_hasPathSum(root->right, path_sum)) return true;
            path_sum -= root->right->val;
        }
        return false;
    }
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        this->sum = sum;
        int path_sum = root->val;
        return _hasPathSum(root, path_sum);
    }
};