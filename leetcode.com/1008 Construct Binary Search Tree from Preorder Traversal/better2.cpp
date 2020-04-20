#include <iostream>
#include <vector>
#include <stack>

#include "leetcode.hpp"

using namespace std;

// ref: Python stack solution beats 100% on runtime and memory
// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/discuss/252722/Python-stack-solution-beats-100-on-runtime-and-memory

class Solution {
 public:
  TreeNode* bstFromPreorder(vector<int>& preorder) {
    int n = preorder.size();
    if (n == 0) return nullptr;
    stack<TreeNode*> stk;
    TreeNode* root = new TreeNode(preorder[0]);
    stk.push(root);
    for (int i = 1; i < n; ++i) {
      TreeNode* cur = new TreeNode(preorder[i]);
      if (cur->val < stk.top()->val) {
        stk.top()->left = cur;
      } else {
        TreeNode *last;
        while (!stk.empty() && stk.top()->val < cur->val) {
          last = stk.top();stk.pop();
        }
        last->right = cur;
      }
      stk.push(cur);
    }
    return root;
  }
};
