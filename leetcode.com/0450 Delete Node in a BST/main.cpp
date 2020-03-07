#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 private:
  // always rotate right
  TreeNode *deleteRoot(TreeNode *root) {
    TreeNode *right = root->right, *left = root->left;
    delete root;
    if (right == nullptr)
      return left;
    else if (left == nullptr)
      return right;

    TreeNode *pnode = left->right;
    left->right = right;
    if (pnode) {
      while (right->left) right = right->left;
      right->left = pnode;
    }
    return left;
  }

 public:
  TreeNode *deleteNode(TreeNode *root, int key) {
    if (!root)
      return root;
    else if (root->val == key)
      return deleteRoot(root);
    TreeNode *pre = nullptr, *cur = root;
    while (cur) {
      if (cur->val == key) {
        break;
      } else if (cur->val < key) {
        pre = cur;
        cur = cur->right;
      } else {
        pre = cur;
        cur = cur->left;
      }
    }
    if (cur) {
      if (pre->left == cur)
        pre->left = deleteRoot(cur);
      else
        pre->right = deleteRoot(cur);
    }
    return root;
  }
};