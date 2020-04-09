#include <iostream>
#include <vector>
#include <numeric>

#include "leetcode.hpp"

using namespace std;

class Solution {
private:
  TreeNode* buildTree(vector<int>&nums, vector<int>::iterator l, vector<int>::iterator r) {
    if (l == r) return nullptr;
    auto it = max_element(l, r);
    TreeNode *root = new TreeNode(*it);
    root->left = buildTree(nums, l, it);
    root->right = buildTree(nums, next(it), r);
    return root;
  }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return buildTree(nums, nums.begin(), nums.end());
    }
};