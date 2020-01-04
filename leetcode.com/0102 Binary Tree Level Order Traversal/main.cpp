#include <iostream>
#include <vector>
#include <queue>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q[2];
        vector<vector<int>> result;
        vector<int> level;
        bool index = false;
        if (root) q[index].push(root);
        while (!q[index].empty()) {
            TreeNode *pnode = q[index].front(); q[index].pop();
            if (pnode->left) q[!index].push(pnode->left);
            if (pnode->right) q[!index].push(pnode->right);
            level.push_back(pnode->val);
            if (q[index].empty()) {
                result.push_back(level);
                level.clear();
                index = !index;
            }
        }
        return result;
    }
};