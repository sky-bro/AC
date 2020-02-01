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
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        int cnt = 0;
        while (!stk.empty() || root) {
            if (root) {
                stk.push(root);
                root = root->left;
            } else {
                root = stk.top(); stk.pop();
                if (++cnt == k) return root->val;
                root = root->right;
            }
        }
        return -1;
    }
};