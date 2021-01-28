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
  int res;
  void dfs(TreeNode *t, int &node_cnt, int &coin_cnt) {
    if (!t) {
      node_cnt = coin_cnt = 0;
      return;
    }
    int lnode_cnt, lcoin_cnt, rnode_cnt, rcoin_cnt;
    dfs(t->left, lnode_cnt, lcoin_cnt);
    if (lnode_cnt > lcoin_cnt) {
      res += lnode_cnt - lcoin_cnt;
    }
    dfs(t->right, rnode_cnt, rcoin_cnt);
    if (rnode_cnt > rcoin_cnt) {
      res += rnode_cnt - rcoin_cnt;
    }
    node_cnt = lnode_cnt + rnode_cnt + 1;
    coin_cnt = lcoin_cnt + rcoin_cnt + t->val;
    if (node_cnt < coin_cnt) {
      res += coin_cnt - node_cnt;
    }
  }

 public:
  int distributeCoins(TreeNode *root) {
    res = 0;
    int a, b;
    dfs(root, a, b);
    return res;
  }
};
