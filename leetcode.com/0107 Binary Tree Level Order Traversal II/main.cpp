#include <iostream>
#include <vector>
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result0;
        if (!root) return result0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int len = q.size();
            vector<int> level(len);
            for (int i = 0; i < len; ++i) {
                TreeNode *pnode = q.front(); q.pop();
                level[i] = pnode->val;
                if (pnode->left) q.push(pnode->left);
                if (pnode->right) q.push(pnode->right);
            }
            result0.push_back(level);
        }
        vector<vector<int>> result(result0.rbegin(), result0.rend());
        return result;
    }
};