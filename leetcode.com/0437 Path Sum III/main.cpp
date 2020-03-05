#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// not efficient, stupid solution
class Solution {
 private:
  void dfs(TreeNode *root, const unordered_multiset<int> &sums, int target_sum,
           int &res) {
    unordered_multiset<int> next_sums;
    next_sums.insert(0);
    transform(sums.begin(), sums.end(), inserter(next_sums, nullptr),
              [&res, target_sum, root](int num) {
                int next_num = num + root->val;
                if (next_num == target_sum) ++res;
                return next_num;
              });
    if (root->left) dfs(root->left, next_sums, target_sum, res);
    if (root->right) dfs(root->right, next_sums, target_sum, res);
  }

 public:
  int pathSum(TreeNode *root, int sum) {
    if (!root) return 0;
    unordered_multiset<int> sums;
    sums.insert(0);
    int res = 0;
    dfs(root, sums, sum, res);
    return res;
  }
};