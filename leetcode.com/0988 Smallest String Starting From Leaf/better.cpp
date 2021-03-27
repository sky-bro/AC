#include <bits/stdc++.h>
using namespace std;
int __fastio = []() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } ();

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
public:
  string smallestFromLeaf(TreeNode *root, string s = "") {
      if (!root) return string(1, 'z' + 1); // 'z' + 1
      s = string(1, root->val + 'a') + s;
      return root->left == root->right ? s : min(smallestFromLeaf(root->left, s), smallestFromLeaf(root->right, s));
  }
};
