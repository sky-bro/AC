#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  bool flipEquiv(TreeNode *root1, TreeNode *root2) {
    if (bool(root1) ^ bool(root2)) return false;
    if (!root1) return true;  // null, null
    if (root1->val != root2->val) return false;
    if (flipEquiv(root1->left, root2->left) &&
        flipEquiv(root1->right, root2->right))
      return true;
    if (flipEquiv(root1->right, root2->left) &&
        flipEquiv(root1->left, root2->right))
      return true;
    return false;
  }
};
