#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 private:
  vector<int> res;
  TreeNode* target;
  int k;
  void bfs(TreeNode* root, int dep) {
    if (!root) return;
    if (dep == 0) {
      res.push_back(root->val);
      return;
    }
    queue<TreeNode*> q;
    int d = 0;
    q.push(root);
    while (!q.empty()) {
      ++d;
      for (int sz = q.size(); sz; --sz) {
        TreeNode* n = q.front();
        q.pop();
        if (n->left) {
          q.push(n->left);
          if (d == dep) res.push_back(n->left->val);
        }
        if (n->right) {
          q.push(n->right);
          if (d == dep) res.push_back(n->right->val);
        }
      }
      if (d == dep) break;
    }
  }

  int dfs(TreeNode* root) {
    if (!root) return -1;
    if (root == target) {
      bfs(root, k);
      return 0;
    }
    int d = -1;
    d = max(d, dfs(root->left));
    if (d >= 0) {
      if (d + 1 == k) {
        res.push_back(root->val);
      } else if (d + 2 <= k)
        bfs(root->right, k - 2 - d);
    } else {
      d = max(d, dfs(root->right));
      if (d >= 0) {
        if (d + 1 == k) {
          res.push_back(root->val);
        } else if (d + 2 <= k)
          bfs(root->left, k - 2 - d);
      }
    }
    return d == -1 ? -1 : d + 1;
  }

 public:
  vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
    res.clear();
    if (K == 0) {
      res.push_back(target->val);
      return res;
    }
    this->target = target;
    k = K;
    dfs(root);
    return res;
  }
};
