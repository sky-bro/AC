#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second > b.second;
}

class Solution {
private:
    unordered_map<int, int> m;
    
    void traverse(TreeNode* root) {
        if (!root) return;
        m[root->val]++;
        traverse(root->left);
        traverse(root->right);
    }
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        traverse(root);
        vector<pair<int, int>> vp(m.begin(), m.end());
        sort(vp.begin(), vp.end(), cmp);
        int max_freq = vp[0].second;
        for (int i = 0; i < vp.size() && vp[i].second == max_freq; ++i) {
            result.push_back(vp[i].first);
        }
        return result;
    }
};
