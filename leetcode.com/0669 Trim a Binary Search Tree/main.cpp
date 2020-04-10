#include <iostream>
#include <vector>

#include "leetcode.hpp"

using namespace std;

// make good use of bst's property
class Solution {
 public:
  TreeNode* trimBST(TreeNode* root, int L, int R) {
    if (!root) return nullptr;
    if (root->val > R) return trimBST(root->left, L, R);
    if (root->val < L) return trimBST(root->right, L, R);
    root->left = trimBST(root->left, L, R);
    root->right = trimBST(root->right, L, R);
    return root;
  }
};