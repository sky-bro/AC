#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 private:
  int res;
  pair<int, int> helper(TreeNode* root) {
    pair<int, int> p;
    if (root->left) {
      p.first = helper(root->left).second + 1;
    }
    if (root->right) {
      p.second = helper(root->right).first + 1;
    }
    res = max(max(p.first, p.second), res);
    return p;
  }

 public:
  int longestZigZag(TreeNode* root) {
    if (!root) return 0;
    res = 0;
    helper(root);
    return res;
  }
};