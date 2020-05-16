#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int goodNodes(TreeNode* root, int pre=INT32_MIN) {
        int res = 0, npre = pre;
        if (root->val >= pre) {++res; npre=root->val;}
        if (root->left) res += goodNodes(root->left, npre);
        if (root->right) res += goodNodes(root->right, npre);
        return res;
    }
};
