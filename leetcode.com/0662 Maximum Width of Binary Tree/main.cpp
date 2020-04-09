#include <iostream>
#include <queue>
#include <vector>

#include "leetcode.hpp"

using namespace std;

// bfs
// careful with integer overflow

// class Solution {
//  public:
//   int widthOfBinaryTree(TreeNode* root) {
//     if (!root) return 0;
//     int res = 1;
//     uint64_t mask = (1ULL << 32) - 1;
//     queue<pair<TreeNode*, uint64_t>> q;
//     q.emplace(root, 1);
//     while (!q.empty()) {
//       int left = q.front().second;
//       bool compute = q.size() > 1;
//       for (int sz = q.size(); sz > 0; --sz) {
//         auto p = q.front();
//         q.pop();
//         if (sz == 1 && compute) res = max(uint64_t(res), p.second - left + 1);
//         if (p.first->left) q.emplace(p.first->left, (p.second * 2) & mask);
//         if (p.first->right)
//           q.emplace(p.first->right, (p.second * 2 + 1) & mask);
//       }
//     }
//     return res;
//   }
// };

class Solution {
 public:
  int widthOfBinaryTree(TreeNode* root) {
    if (!root) return 0;
    uint32_t res = 1;
    queue<pair<TreeNode*, uint32_t>> q;
    q.emplace(root, 1);
    while (!q.empty()) {
      int left = q.front().second;
      bool compute = q.size() > 1;
      for (int sz = q.size(); sz > 0; --sz) {
        auto p = q.front();
        q.pop();
        if (sz == 1 && compute) res = max(res, p.second - left + 1);
        if (p.first->left) q.emplace(p.first->left, p.second * 2ul);
        if (p.first->right)
          q.emplace(p.first->right, p.second * 2ul + 1);
      }
    }
    return res;
  }
};