#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
  int res = INT32_MAX;
  TreeNode* pre;
public:
    int minDiffInBST(TreeNode* root) {
      if (root->left) {
        res = min(res, minDiffInBST(root->left));
      }
      if (pre) {
        res = min(res, root->val - pre->val);
      }
      pre = root;
      if (root->right) {
        res = min(res, minDiffInBST(root->right));
      }
      return res;
    }
};
