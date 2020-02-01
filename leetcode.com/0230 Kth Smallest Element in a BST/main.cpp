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
private:
    int cnt, k, result;
    void inorder_traversal(TreeNode* root) {
        if (root->left) inorder_traversal(root->left);
        if (cnt == k) return;
        if (++cnt == k) result = root->val;
        if (cnt != k && root->right) inorder_traversal(root->right);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        cnt = 0;
        this->k = k;
        inorder_traversal(root);
        return result;
    }
};