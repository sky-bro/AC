#include <iostream>
#include <vector>

#include "leetcode.hpp"

using namespace std;

class Solution {
 private:
  void right2left(TreeNode* root, int& pre) {
    if (root->right) right2left(root->right, pre);
    pre = root->val += pre;
    if (root->left) right2left(root->left, pre);
  }

 public:
  TreeNode* convertBST(TreeNode* root) {
    int pre = 0;
    if (!root) return nullptr;
    right2left(root, pre);
    return root;
  }
};