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
  vector<int> szs, res;
  int n;
  bool ok;
  int dfs(TreeNode *t) {
    if (!t) return 0;
    int sz = 1 + dfs(t->left) + dfs(t->right);
    return szs[t->val] = sz;
  }
  bool dfs2(TreeNode *t, int l, int r, vector<int> &v) {
    if (!t) return true;
    int sz = r - l;
    if (t->val != v[l] || szs[t->val] != sz) return false;
    if (t->left == nullptr && t->right == nullptr) return true;
    if (bool(t->left) ^ bool(t->right)) {
      if (t->left) {
        return dfs2(t->left, l + 1, r, v);
      } else {
        return dfs2(t->right, l + 1, r, v);
      }
    }
    if (t->left->val == v[l + 1]) {  // no swap
      sz = szs[t->left->val];
      return dfs2(t->left, l + 1, l + 1 + sz, v) &&
             dfs2(t->right, l + 1 + sz, r, v);
    } else {  // swap
      res.push_back(t->val);
      sz = szs[t->right->val];
      return dfs2(t->right, l + 1, l + 1 + sz, v) &&
             dfs2(t->left, l + 1 + sz, r, v);
    }
  }

 public:
  vector<int> flipMatchVoyage(TreeNode *root, vector<int> &voyage) {
    n = voyage.size();
    szs.resize(n + 1);
    dfs(root);
    if (dfs2(root, 0, n, voyage))
      return res;
    else
      return {-1};
  }
};
