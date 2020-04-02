#include <iostream>
#include <vector>

#include "leetcode.hpp"

using namespace std;

class Solution {
 private:
  TreeNode* copyTree(TreeNode* t) {
    if (!t) return nullptr;
    TreeNode* new_t = new TreeNode(t->val);
    new_t->left = copyTree(t->left);
    new_t->right = copyTree(t->right);
    return new_t;
  }

 public:
  TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if (!t1) return copyTree(t2);
    if (!t2) return copyTree(t1);
    TreeNode* t = new TreeNode(t1->val + t2->val);
    t->left = mergeTrees(t1->left, t2->left);
    t->right = mergeTrees(t1->right, t2->right);
    return t;
  }
};