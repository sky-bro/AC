#include <cstring>
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

// recursive
int sib[1010];  // parent | leftchild | rightchild (30 bits)
// int outdegree[1010];
class Solution {
 private:
  int n;
  const int mask = (1 << 10) - 1;
  void dfs(TreeNode *t) {
    if (!t) return;
    int id = n++;
    t->val = id;
    if (t->left) {
      sib[n] = id << 20;  // parent
      sib[id] |= n << 10;     // leftchild
                              //   ++outdegree[t->val];
      dfs(t->left);
    }
    if (t->right) {
      sib[n] = id << 20;
      sib[id] |= n;  // rightchild
                     //   ++outdegree[t->val];
      dfs(t->right);
    }
  }

 public:
  int minCameraCover(TreeNode *root) {
    n = 0;
    // memset(outdegree, 0, sizeof(outdegree));
    sib[0] = 0;
    dfs(root);
    vector<bool> ok(n);  // 0: unmonitored, 1: monitored
    // vector<int> ok(n); // 0: unmonitored, 1: no camera, but monitored, 2:
    // camera
    int res = 0;
    bool changed = true;
    while (changed) {
      changed = false;
      for (int i = n; i >= 0; --i) {
        if (ok[i]) continue;  // visited
        int l = (sib[i] >> 10) & mask, r = sib[i] & mask,
            p = (sib[i] >> 20) & mask;
        if ((!l || ok[l]) && (!r || ok[r])) {
          changed = true;
          ++res;
          ok[p] = true;
          int pl = (sib[p] >> 10) & mask, pr = sib[p] & mask,
              pp = (sib[p] >> 20) & mask;
          ok[pp] = true;
          if (pl) ok[pl] = true;
          if (pr) ok[pr] = true;
        }
      }
    }
    return res;
  }
};

/*
[0,null,0,0,0,null,0,null,0,null,null,0,null,0,null,null,0,null,0,0]
    0
   x   0
    0    0
   x 0  x   0
    x x    0 x
          0 x
         x 0
          x 0
           0
    0
   x   1
    1    0
   x 0  x   0
    x x    1 x
          0 x
         x 0
          x 1
           0
*/
