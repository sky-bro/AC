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

vector<vector<TreeNode *>> d(21);
class Solution {
 private:
  void f(int n) {
    if (n == 1) {
      d[1].push_back(new TreeNode());
      return;
    }
    for (int i = 1; i <= n - 2; ++i) {
      if (d[i].empty()) f(i);
      if (d[n - 1 - i].empty()) f(n - 1 - i);
      for (auto l : d[i]) {
        for (auto r : d[n - 1 - i]) {
          TreeNode *root = new TreeNode();
          root->left = l;
          root->right = r;
          d[n].push_back(root);
        }
      }
    }
  }

 public:
  vector<TreeNode *> allPossibleFBT(int N) {
    if ((N & 1) == 0) return {};
    if (d[N].empty()) f(N);
    return d[N];
  }
};
