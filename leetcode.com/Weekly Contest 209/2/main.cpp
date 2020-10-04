#include <bits/stdc++.h>
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
  bool isEvenOddTree(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);
    bool even = true;
    while (!q.empty()) {
      int sz = q.size();
      int pre = even ? 0 : INT32_MAX;
      for (int i = 0; i < sz; ++i) {
        auto cur = q.front();
        q.pop();
        if (cur->left) {
          q.push(cur->left);
        }
        if (cur->right) {
          q.push(cur->right);
        }
        if (even) {
          if (((cur->val & 1) == 0) || cur->val <= pre) return false;
          pre = cur->val;
        } else {
          if ((cur->val & 1) || cur->val >= pre) return false;
          pre = cur->val;
        }
      }
      even = !even;
    }
    return true;
  }
};
