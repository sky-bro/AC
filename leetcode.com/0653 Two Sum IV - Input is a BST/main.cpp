#include <iostream>
#include <vector>

#include "leetcode.hpp"

using namespace std;

class Solution {
 private:
  void in_order(TreeNode* root, vector<int>& nums) {
    if (!root) return;
    in_order(root->left, nums);
    nums.push_back(root->val);
    in_order(root->right, nums);
  }

 public:
  bool findTarget(TreeNode* root, int k) {
    vector<int> nums;
    in_order(root, nums);
    int l = 0, r = nums.size() - 1;
    while (l < r) {
      int sum = nums[l] + nums[r];
      if (sum == k)
        return true;
      else if (sum < k)
        ++l;
      else
        --r;
    }
    return false;
  }
};