#include <iostream>
#include <vector>

#include "leetcode.hpp"

using namespace std;

class Solution {
 private:
  int res;
  int depth(TreeNode* root) {
    if (!root) return 0;
    int ld = 0, rd = 0;
    if (root->left) ld = depth(root->left);
    if (root->right) rd = depth(root->right);
    res = max(res, ld + rd);
    return max(ld, rd) + 1;
  }

 public:
  int diameterOfBinaryTree(TreeNode* root) {
    res = 0;
    depth(root);
    return res;
  }
};