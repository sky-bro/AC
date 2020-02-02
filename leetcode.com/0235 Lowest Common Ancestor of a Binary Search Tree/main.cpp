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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;
        if (p) {
            if (!q) return p;
        } else if (q) {
            return q;
        } else {
            while (root->left) root = root->left;
            return root;
        }

        // root != nullptr && p != nullptr && q != nullptr

        if (p->val > q->val) return lowestCommonAncestor(root, q, p);

        while (!(root->val >= p->val && root->val <= q->val)) {
            if (root->val > q->val) root = root->left;
            else if (root->val < p->val) root = root->right;
        }
        return root;
    }
};