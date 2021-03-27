#include <bits/stdc++.h>
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
public:
  string smallestFromLeaf(TreeNode *root) {
      string res;
      int id = 0;
      vector<int> pa;
      pa.push_back(-1);
      stack<int> stk;
      stk.push(0);
      vector<TreeNode*> v;
      v.push_back(root);
      priority_queue<array<int, 3>, vector<array<int,3>>, greater<array<int,3>>> pq; // dep, code
      
      while (!stk.empty()) {
          int p = stk.top(); stk.pop();
          if (v[p]->left) {
              stk.push(++id);
              pa.push_back(p);
              v.push_back(v[p]->left);
          }
          if (v[p]->right) {
              stk.push(++id);
              pa.push_back(p);
              v.push_back(v[p]->right);
          }
          if (!v[p]->left && !v[p]->right) {
              pq.push({0, v[p]->val + 'a', p});
          }
      }
      vector<bool> vis(id);
      while (1) {
          auto t = pq.top(); pq.pop();
          if (t[0] == res.size()) {
              res.push_back(t[1]);
              if (t[2] == 0) break;
              vis[t[2]] = true;
          } else if (t[1] > res[t[0]] || vis[t[2]]) continue;
          int p = pa[t[2]];
          ++t[0];
          t[1] = v[p]->val + 'a';
          t[2] = p;
          pq.push(t);
      }
      return res;
  }
};
