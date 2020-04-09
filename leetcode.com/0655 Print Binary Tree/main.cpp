#include <cmath>
#include <iostream>
#include <vector>

#include "leetcode.hpp"

using namespace std;

class Solution {
 private:
  int get_height(TreeNode *root) {
    if (!root) return 0;
    return max(get_height(root->left), get_height(root->right)) + 1;
  }
  void dfs(TreeNode *root, int h, int l, int r, vector<vector<string>> &res) {
    if (!root) return;
    int mid = (l + r) / 2;
    res[h][mid] = to_string(root->val);
    dfs(root->left, h + 1, l, mid - 1, res);
    dfs(root->right, h + 1, mid + 1, r, res);
  }

 public:
  vector<vector<string>> printTree(TreeNode *root) {
    if (!root) return {};
    int m = get_height(root), n = (1 << m) - 1;
    vector<vector<string>> res(m, vector<string>(n, ""));
    dfs(root, 0, 0, n - 1, res);
    return res;
  }
};