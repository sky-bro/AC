#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

#include "leetcode.hpp"

using namespace std;

class Solution {
 private:
  vector<int> res;
  unordered_map<int, int> m;
  int tree_sum(TreeNode* root) {
    int sum = root->val;
    if (root->left) sum += tree_sum(root->left);
    if (root->right) sum += tree_sum(root->right);
    m[sum]++;
    return sum;
  }

 public:
  vector<int> findFrequentTreeSum(TreeNode* root) {
    res.clear();
    if (!root) return res;
    tree_sum(root);
    set<pair<int, int>> s;
    for (auto& p : m) {
      s.emplace(-p.second, p.first);
    }
    auto it = s.begin();
    int cnt = it->first;
    for (; it != s.end() && it->first == cnt; ++it) {
      res.push_back(it->second);
    }
    return res;
  }
};