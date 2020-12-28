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
    void dfs(TreeNode*root, TreeNode*&l, TreeNode*&r) {
        if (root->left) {
            dfs(root->left, l, r);
            r->right = root;
            root->left = nullptr;
        } else {
            l = root;
        }
        r = root;
        if (root->right) {
            dfs(root->right, r->right, r);
        }
    }
public:
  TreeNode *increasingBST(TreeNode *root) {
      TreeNode *l,*r;
      dfs(root, l, r);
      return l;
  }
};
