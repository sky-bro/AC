#include <iostream>
#include <vector>

#include "leetcode.hpp"

using namespace std;

class Solution {
 private:
  int res;
  int dfs(TreeNode* root) {
    if (!root) return 0;
    int l = dfs(root->left);
    int r = dfs(root->right);
    res += abs(l - r);
    return l + r + root->val;
  }

 public:
  int findTilt(TreeNode* root) {
    res = 0;
    dfs(root);
    return res;
  }
};