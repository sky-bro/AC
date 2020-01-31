#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> q;
        if (!root) return root;
        q.push(root);
        while (!q.empty()) {
            TreeNode* pnode = q.front(); q.pop();
            swap(pnode->left, pnode->right);
            if (pnode->left) q.push(pnode->left);
            if (pnode->right) q.push(pnode->right);
        }
        return root;
    }
};