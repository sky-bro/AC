#include <iostream>
#include <vector>

#include "leetcode.hpp"

using namespace std;

class Solution {
 public:
  int findSecondMinimumValue(TreeNode* root) {
    if (!root || !root->left) return -1;

    int res1 = -1, res2 = -1;

    if (root->left->val == root->val)
      res1 = findSecondMinimumValue(root->left);
    else
      res1 = root->left->val;

    if (root->right->val == root->val)
      res2 = findSecondMinimumValue(root->right);
    else
      res2 = root->right->val;

    if (res1 == -1)
      return res2;
    else if (res2 == -1)
      return res1;
    else
      return min(res1, res2);
  }
};