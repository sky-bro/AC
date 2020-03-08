#include <iostream>
#include <vector>
#include "../../inlcude/leetcode.hpp"

using namespace std;

class Solution {
 private:
  int res;
  // buttom up
  int helper(TreeNode *root, int &min_num, int &max_num) {
    bool valid = true;
    int sum = 0, left_sum = 0, right_sum = 0;
    int left_min_num, left_max_num, right_min_num, right_max_num;
    if (root->left) {
      left_sum = helper(root->left, left_min_num, left_max_num);
      if (left_sum == INT32_MIN || left_max_num >= root->val) {
        valid = false;
      }
    } else {
      left_min_num = root->val;
    }
    if (root->right) {
      right_sum = helper(root->right, right_min_num, right_max_num);
      if (right_sum == INT32_MIN || right_min_num <= root->val) {
        valid = false;
      }
    } else {
      right_max_num = root->val;
    }
    if (!valid) return INT32_MIN;
    min_num = left_min_num;
    max_num = right_max_num;
    res = max(res, sum = root->val + left_sum + right_sum);
    return sum;
  }

 public:
  int maxSumBST(TreeNode *root) {
    res = 0;
    if (!root) return 0;
    int min_num, max_num, sum = 0;
    helper(root, min_num, max_num);
    return res;
  }
};

int main() {
  string line;
  while (getline(cin, line)) {
    TreeNode *root = stringToTreeNode(line);

    int ret = Solution().maxSumBST(root);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}