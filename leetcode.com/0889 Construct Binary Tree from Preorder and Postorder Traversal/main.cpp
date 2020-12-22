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

int num2idx1[31];
int num2idx2[31];

class Solution {
 private:
  int n;
  TreeNode *f(int l1, int r1, int l2, int r2, vector<int> &pre,
              vector<int> &post) {
    TreeNode *root = new TreeNode(pre[l1]);
    if (l1 == r1) return root;
    int num1 = pre[l1 + 1], num2 = post[r2 - 1];
    if (num1 == num2) {
      root->left = f(l1 + 1, r1, l2, r2 - 1, pre, post);
    } else {
      int sp1 = num2idx1[num2], sp2 = num2idx2[num1];
      root->left = f(l1 + 1, sp1 - 1, l2, sp2, pre, post);
      root->right = f(sp1, r1, sp2 + 1, r2 - 1, pre, post);
    }
    return root;
  }

 public:
  TreeNode *constructFromPrePost(vector<int> &pre, vector<int> &post) {
    n = pre.size();
    for (int i = 0; i < n; ++i) {
      num2idx1[pre[i]] = i;
      num2idx2[post[i]] = i;
    }
    return f(0, n - 1, 0, n - 1, pre, post);
  }
};
