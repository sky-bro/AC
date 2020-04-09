#include <iostream>
#include <numeric>
#include <vector>

#include "leetcode.hpp"

using namespace std;

// great solution (use stack, one pass) from:
// https://leetcode.com/problems/maximum-binary-tree/discuss/106146/C%2B%2B-O(N)-solution

class Solution {
 public:
  TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    vector<TreeNode*> stk;
    for (int i = 0; i < nums.size(); ++i) {
      TreeNode* cur = new TreeNode(nums[i]);
      while (!stk.empty() && stk.back()->val < nums[i]) {
        cur->left = stk.back();
        stk.pop_back();
      }
      if (!stk.empty()) stk.back()->right = cur;
      stk.push_back(cur);
    }
    return stk.front();
  }
};
