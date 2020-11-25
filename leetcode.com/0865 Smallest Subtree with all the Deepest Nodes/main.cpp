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
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 private:
  TreeNode *res;
  int dfs(TreeNode *root) {
    if (!root) return 0;
    int l = dfs(root->left);
    int r = dfs(root->right);
    return max(l, r) + 1;
  }

 public:
  TreeNode *subtreeWithAllDeepest(TreeNode *root) {
    int l = dfs(root->left);
    int r = dfs(root->right);
    if (l == r) {
      return root;
    } else if (l < r) {
      return subtreeWithAllDeepest(root->right);
    } else {
      return subtreeWithAllDeepest(root->left);
    }
  }
};
