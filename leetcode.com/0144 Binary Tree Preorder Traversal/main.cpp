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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> result;
        if (!root) return result;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode *tmp = stk.top(); stk.pop();
            result.push_back(tmp->val);
            if (tmp->right) stk.push(tmp->right);
            if (tmp->left) stk.push(tmp->left);
        }
        return result;
    }
};