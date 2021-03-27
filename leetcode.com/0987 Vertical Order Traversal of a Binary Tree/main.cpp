#include <bits/stdc++.h>
using namespace std;
int __fastio = []() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } ();

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
private:
    map<int, map<int, multiset<int>>> m; // c->r->vs
    void dfs(TreeNode* root, int r, int c) {
        if (!root) return;
        m[c][r].insert(root->val);
        dfs(root->left, r + 1, c - 1);
        dfs(root->right, r + 1, c + 1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        m.clear();
        dfs(root, 0, 0);
        int n = m.size();
        res.resize(n);
        int i = 0;
        for (auto &C: m) {
            for (auto &R: C.second) {
                for (int v: R.second) {
                    res[i].push_back(v);
                }
            }
            ++i;
        }
        return res;
    }
};
