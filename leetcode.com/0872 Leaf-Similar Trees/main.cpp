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
  vector<int> stk;
  void dfs(TreeNode *root1) {
    if (root1->left == nullptr && root1->right == nullptr) {
      stk.push_back(root1->val);
      return;
    }
    if (root1->left) {
      dfs(root1->left);
    }
    if (root1->right) {
      dfs(root1->right);
    }
  }

  bool dfs2(TreeNode *root2) {
    if (root2->left == nullptr && root2->right == nullptr) {
      if (stk.empty()) return false;
      if (stk.back() != root2->val) return false;
      stk.pop_back();
      return true;
    }
    if (root2->right) {
      if (dfs2(root2->right) == false) return false;
    }
    if (root2->left) {
      if (dfs2(root2->left)) return true;
      return false;
    }
    return true;
  }

 public:
  bool leafSimilar(TreeNode *root1, TreeNode *root2) {
    stk.clear();
    dfs(root1);
    return dfs2(root2) && stk.empty();
  }
};
