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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q; q.push(root);
        int result = 0;
        while (!q.empty()) {
            ++result;
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                TreeNode* pnode = q.front(); q.pop();
                if (pnode->left) q.push(pnode->left);
                if (pnode->right) q.push(pnode->right);
                if (pnode->left == nullptr && pnode->right == nullptr) return result;
            }
        }
        // control won't reach here
        return -1;
    }
};