#include <iostream>
#include <vector>

#include "leetcode.hpp"

using namespace std;

class Solution {
 private:
  TreeNode* helper(vector<int>& nums, int l, int r) {
    if (l == r) return new TreeNode(nums[l]);
    if (l > r) return nullptr;
    TreeNode* root = new TreeNode(nums[l]);
    auto it = lower_bound(nums.begin() + l + 1, nums.begin() + r + 1, nums[l]);
    if (it == nums.begin() + l + 1) {
      root->right = helper(nums, l + 1, r);
    } else if (it == nums.begin() + r + 1) {
      root->left = helper(nums, l + 1, r);
    } else {
      root->left = helper(nums, l + 1, it - nums.begin() - 1);
      root->right = helper(nums, it - nums.begin(), r);
    }
    return root;
  }

 public:
  TreeNode* bstFromPreorder(vector<int>& preorder) {
    return helper(preorder, 0, int(preorder.size()) - 1);
  }
};
