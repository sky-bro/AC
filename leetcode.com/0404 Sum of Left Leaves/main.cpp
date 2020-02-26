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
  int dfs(TreeNode *root, bool isleft) {
    if (isleft && !root->left && !root->right) return root->val;
    int res = 0;
    if (root->left) res += dfs(root->left, true);
    if (root->right) res += dfs(root->right, false);
    return res;
  }

 public:
  int sumOfLeftLeaves(TreeNode *root) {
    if (!root) return 0;
    return dfs(root, false);
  }
};