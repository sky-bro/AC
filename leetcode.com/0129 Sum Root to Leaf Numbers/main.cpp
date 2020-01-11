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
    int cur;
    void _sumNumbers(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) {
            sum += cur;
            return;
        }
        cur *= 10;
        if (root->left) {
            cur += root->left->val;
            _sumNumbers(root->left);
            cur -= root->left->val;
        }
        if (root->right) {
            cur += root->right->val;
            _sumNumbers(root->right);
            cur -= root->right->val;
        }
        cur /= 10;
    }
public:
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        sum = 0;
        cur = root->val;
        _sumNumbers(root);
        return sum;
    }
};