#include <iostream>
#include <vector>

#include "leetcode.hpp"

using namespace std;

// ref: [Java/C++/Python] O(N) Solution
// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/discuss/252232/JavaC%2B%2BPython-O(N)-Solution

class Solution {
 private:
  TreeNode* helper(vector<int> nums, int& i, int rb) {
    if (i == nums.size() || nums[i] > rb) return nullptr;
    TreeNode* root = new TreeNode(nums[i]);
    root->left = helper(nums, i, nums[i++]);
    root->right = helper(nums, i, rb);
    return root;
  }

 public:
  TreeNode* bstFromPreorder(vector<int>& preorder) {
    int i = 0;
    return helper(preorder, i, INT32_MAX);
  }
};
