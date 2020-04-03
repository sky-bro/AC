#include <iostream>
#include <queue>
#include <vector>

#include "leetcode.hpp"

using namespace std;

class Solution {
 public:
  vector<double> averageOfLevels(TreeNode* root) {
    vector<double> res;
    if (!root) return res;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      double sum = 0;
      int sz = q.size();
      for (int i = 0; i < sz; ++i) {
        TreeNode* t = q.front();
        q.pop();
        sum += t->val;
        if (t->left) q.push(t->left);
        if (t->right) q.push(t->right);
      }
      res.push_back(sum / sz);
    }
    return res;
  }
};