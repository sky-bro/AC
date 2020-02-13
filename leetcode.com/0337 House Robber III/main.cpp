#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// TLE
class Solution0 {
private:
    int dfs(TreeNode* root, bool rob_cur) {
        int res = rob_cur ? root->val : 0;
        if (root->left) res += rob_cur ? dfs(root->left, false) : max(dfs(root->left, false), dfs(root->left, true));
        if (root->right) res += rob_cur ? dfs(root->right, false) : max(dfs(root->right, false), dfs(root->right, true));
        return res;
    }
public:
    int rob(TreeNode* root) {
        if (!root) return 0;
        return max(dfs(root, true), dfs(root, false));
    }
};

class Solution {
private:
    unordered_map<TreeNode*, int> mp_with_cur;
    unordered_map<TreeNode*, int> mp_without_cur;
    int dfs(TreeNode* root, bool rob_cur) {
        if (rob_cur) {
            auto it = mp_with_cur.find(root);
            if (it != mp_with_cur.end()) return it->second;
        } else {
            auto it = mp_without_cur.find(root);
            if (it != mp_without_cur.end()) return it->second;
        }
        
        int res = rob_cur ? root->val : 0;
        if (root->left) res += rob_cur ? dfs(root->left, false) : max(dfs(root->left, false), dfs(root->left, true));
        if (root->right) res += rob_cur ? dfs(root->right, false) : max(dfs(root->right, false), dfs(root->right, true));

        if (rob_cur) {
            mp_with_cur[root] = res;
        } else {
            mp_without_cur[root] = res;
        }

        return res;
    }
public:
    int rob(TreeNode* root) {
        if (!root) return 0;
        return max(dfs(root, true), dfs(root, false));
    }
};