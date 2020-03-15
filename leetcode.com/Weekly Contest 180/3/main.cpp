#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 private:
  TreeNode* buildTree(vector<int>& nums, int l, int r) {
    if (l > r) return nullptr;
    int mid = l + (r - l) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = buildTree(nums, l, mid - 1);
    root->right = buildTree(nums, mid + 1, r);
    return root;
  }
  void Tree2Vec(vector<int>& nums, TreeNode* root) {
    if (root->left) Tree2Vec(nums, root->left);
    nums.push_back(root->val);
    if (root->right) Tree2Vec(nums, root->right);
  }

 public:
  TreeNode* balanceBST(TreeNode* root) {
    if (!root) return nullptr;
    vector<int> nums;
    Tree2Vec(nums, root);
    return buildTree(nums, 0, nums.size() - 1);
  }
};