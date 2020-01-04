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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) {
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        bool flag = false;
        while (q.size()) {
            int sz = q.size();
            vector<int> row (sz);
            for (int i = 0; i < sz; i++) {
                TreeNode* cur = q.front();
                q.pop();
                
                int idx = i;
                if (flag) {
                    idx = sz - 1 - idx;
                }
                row[idx] = cur->val;
                if (cur->left) {
                    q.push(cur->left);
                }
                if (cur->right) {
                    q.push(cur->right);
                }
                
            }
            res.push_back(move(row));
            flag = !flag;
        }
        return res;
    }
};