#include <iostream>
#include <vector>

#include "leetcode.hpp"

using namespace std;

// recursive
class Solution {
 public:
  TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (root->val > val) {
      root->left = insertIntoBST(root->left, val);
    } else {
      root->right = insertIntoBST(root->right, val);
    }
    return root;
  }
};

// iterative
class Solution2 {
 public:
  TreeNode* insertIntoBST(TreeNode* root, int val) {
    TreeNode* node = root;
    while (1) {
      if (val < node->val) {
        if (node->left) {
          node = node->left;
        } else {
          node->left = new TreeNode(val);
          break;
        }
      } else {
        if (node->right) {
          node = node->right;
        } else {
          node->right = new TreeNode(val);
          break;
        }
      }
    }
    return root;
  }
};