#include <iostream>
#include <vector>

#include "leetcode.hpp"

using namespace std;

class Solution {
 public:
  TreeNode* searchBST(TreeNode* root, int val) {
    while (root && root->val != val) {
      root = root->val > val ? root->left : root->right;
    }
    return root;
  }
};