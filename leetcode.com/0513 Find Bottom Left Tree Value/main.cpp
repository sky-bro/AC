#include <iostream>
#include <queue>
#include <vector>

#include "leetcode.hpp"

using namespace std;

class Solution {
 public:
  int findBottomLeftValue(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    int res;
    while (!q.empty()) {
      res = q.front()->val;
      for (int sz = q.size(); sz > 0; --sz) {
        TreeNode* pn = q.front();
        q.pop();
        if (pn->left) q.push(pn->left);
        if (pn->right) q.push(pn->right);
      }
    }
    return res;
  }
};