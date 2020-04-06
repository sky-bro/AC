#include <iostream>
#include <queue>
#include <vector>

#include "leetcode.hpp"

using namespace std;

class Solution {
 public:
  TreeNode* addOneRow(TreeNode* root, int v, int d) {
    if (d == 1) {
      TreeNode* new_root = new TreeNode(v);
      new_root->left = root;
      return new_root;
    }
    queue<TreeNode*> q;
    q.push(root);
    while (d != 2) {
      --d;
      for (int sz = q.size(); sz > 0; --sz) {
        TreeNode* t = q.front();
        q.pop();
        if (t->left) q.push(t->left);
        if (t->right) q.push(t->right);
      }
    }
    for (int sz = q.size(); sz > 0; --sz) {
      TreeNode* t = q.front();
      q.pop();
      TreeNode* new_left = new TreeNode(v);
      TreeNode* new_right = new TreeNode(v);
      new_left->left = t->left;
      new_right->right = t->right;
      t->left = new_left;
      t->right = new_right;
    }
    return root;
  }
};