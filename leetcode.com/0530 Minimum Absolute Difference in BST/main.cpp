#include <iostream>
#include <vector>

#include "leetcode.hpp"

using namespace std;

class Solution {
 private:
  int res;
  void in_order(TreeNode* root, int& pre) {
    if (root->left) in_order(root->left, pre);
    if (~pre) res = min(res, abs(root->val - pre));
    pre = root->val;
    if (root->right) in_order(root->right, pre);
  }

 public:
  int getMinimumDifference(TreeNode* root) {
    res = INT32_MAX;
    int pre = -1;
    in_order(root, pre);
    return res;
  }
};