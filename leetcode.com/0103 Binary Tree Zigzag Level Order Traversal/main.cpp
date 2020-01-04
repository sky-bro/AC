#include <iostream>
#include <vector>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        bool is_left2right = true;

        stack<TreeNode*> stk[2];
        vector<vector<int>> result;
        vector<int> level;
        if (root) stk[is_left2right].push(root);
        while (!stk[is_left2right].empty()) {
            TreeNode* pnode = stk[is_left2right].top(); stk[is_left2right].pop();
            level.push_back(pnode->val);
            if (is_left2right) {
                if (pnode->left) stk[!is_left2right].push(pnode->left);
                if (pnode->right) stk[!is_left2right].push(pnode->right);
            } else {
                if (pnode->right) stk[!is_left2right].push(pnode->right);
                if (pnode->left) stk[!is_left2right].push(pnode->left);
            }
            if (stk[is_left2right].empty()) {
                result.push_back(level);
                level.clear();
                is_left2right = !is_left2right;
            }
        }
        return result;
    }
};