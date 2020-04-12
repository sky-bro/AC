#include <iostream>
#include <vector>

#include "leetcode.hpp"

using namespace std;

class Solution {
  int res;
  int helper(TreeNode* root) {
    int cur = 0, len = 0;
    if (root->left) {
      int left = helper(root->left);
      if (root->left->val == root->val) {
        cur = len = 1 + left;
      }
    }
    if (root->right) {
      int right = helper(root->right);
      if (root->right->val == root->val) {
        cur += 1 + right;
        len = max(len, 1 + right);
      }
    }
    res = max(res, cur);
    return len;
  }

 public:
  int longestUnivaluePath(TreeNode* root) {
    if (!root) return 0;
    res = 0;
    helper(root);
    return res;
  }
};