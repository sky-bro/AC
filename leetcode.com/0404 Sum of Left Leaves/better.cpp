#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  int sumOfLeftLeaves(TreeNode *root) {
    int res = 0;
    if (!root) return 0;

    if (root->left) {
      if ((!root->left->left) && (!root->left->right))
        res += root->left->val;
      else
        res += sumOfLeftLeaves(root->left);
    }
    if (root->right) res += sumOfLeftLeaves(root->right);

    return res;
  }
};