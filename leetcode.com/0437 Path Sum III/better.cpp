#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//  accumulate sum up to each node
class Solution0 {
 public:
  int ans = 0;
  void helper(TreeNode *root, int curSum, int target,
              unordered_map<int, int> &m) {
    if (root == NULL) {
      return;
    }
    curSum += root->val;
    if (m.find(curSum - target) != m.end()) {
      ans += m[curSum - target];
    }
    m[curSum]++;
    helper(root->left, curSum, target, m);
    helper(root->right, curSum, target, m);

    m[curSum]--;
  }
  int pathSum(TreeNode *root, int sum) {
    if (root == NULL) return 0;
    unordered_map<int, int> m;
    m[0] = 1;
    helper(root, 0, sum, m);
    return ans;
  }
};

// improved from my original solution, idea from Solution0 (but Solution0 is
// faster)
class Solution {
 private:
  int sum, res;
  void dfs(TreeNode *root, unordered_multiset<int> &sums, int cur_sum) {
    cur_sum += root->val;
    res += sums.count(cur_sum - sum);
    sums.insert(cur_sum);
    if (root->left) dfs(root->left, sums, cur_sum);
    if (root->right) dfs(root->right, sums, cur_sum);
    sums.erase(sums.find(cur_sum));
  }

 public:
  int pathSum(TreeNode *root, int sum) {
    if (!root) return 0;
    unordered_multiset<int> sums;
    sums.insert(0);
    this->sum = sum;
    res = 0;
    dfs(root, sums, 0);
    return res;
  }
};

// better, fastest
class Solution2 {
 private:
  int sum, cou = 0;
  vector<int> path;
  void preorder(TreeNode *root) {
    if (root == NULL) return;

    path.push_back(root->val);

    preorder(root->left);
    preorder(root->right);

    int res = 0;

    for (int i = path.size() - 1; i >= 0; i--) {
      res += path[i];
      if (res == sum) cou++;
    }

    path.pop_back();
  }

 public:
  int pathSum(TreeNode *root, int sum) {
    if (root == NULL) return 0;
    this->sum = sum;
    cou = 0;
    path.clear();

    preorder(root);

    return cou;
  }
};

int main(int argc, char const *argv[]) {
  Solution0 s0;
  Solution s1;
  Solution2 s2;
  TreeNode tree(1);
  cout << s0.pathSum(&tree, 0) << endl;
  cout << s1.pathSum(&tree, 0) << endl;
  return 0;
}
