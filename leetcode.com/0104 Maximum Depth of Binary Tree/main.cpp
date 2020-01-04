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
private:
    int max_depth;
    void dfs(TreeNode* root, int cur_depth) {
        if (cur_depth > max_depth) max_depth = cur_depth;
        if (root->left) dfs(root->left, cur_depth + 1);
        if (root->right) dfs(root->right, cur_depth + 1);
    }
public:
    int maxDepth(TreeNode* root) {
        max_depth = 0;
        if (root) dfs(root, 1);
        return max_depth;
    }
};