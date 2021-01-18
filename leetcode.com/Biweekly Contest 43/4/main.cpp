#include <bits/stdc++.h>

using namespace std;

static int x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}();
typedef long long ll;

// ref: https://leetcode.com/problems/number-of-ways-to-reconstruct-a-tree/discuss/1008950/Simple-C%2B%2B-solution
/*
1. 父亲节点一定大于等于儿子节点的邻居（出现在的pairs次数多）
2. 如果等于，那么哪个是父亲节点都行，而且另一个是唯一的儿子节点
3. 父亲节点出现的在pair数一定是儿子的祖先中最少的
4. 父亲节点出现的pair一定包含儿子节点出现在的pair
*/
class Solution {
 public:
  int checkWays(vector<vector<int>>& pairs) {
    unordered_map<int, unordered_set<int>> adj;
    for (int i = 0; i < pairs.size(); i++) {
      adj[pairs[i][0]].emplace(pairs[i][1]);
      adj[pairs[i][1]].emplace(pairs[i][0]);
    }

    priority_queue<pair<int, int>> q;
    for (auto& [x, arr] : adj) {
      q.push({arr.size(), x});
    }

    int n = q.size();  // number of nodes

    bool multiple = false;

    unordered_set<int> seen;
    while (!q.empty()) {
      auto [sz, v] = q.top();
      q.pop();

      int u = 0;  // parent
      int usz = n + 1;
      if (!seen.empty()) {
        for (auto x : adj[v]) {
          if (adj[x].size() < usz && seen.count(x)) {  // find parent
            u = x;
            usz = adj[x].size();  // least degree neighbor as parent
          }
        }
      }

      seen.emplace(v);
      if (u == 0) {
        if (sz != (n - 1)) {
          return 0;
        }

        continue;
      }

      for (auto x : adj[v]) {
        if (x == u) {
          continue;
        }

        if (!adj[u].count(x)) {
          return 0;
        }
      }

      if (usz == sz) {
        multiple = true;
      }
    }

    if (multiple) {
      return 2;
    }

    return 1;
  }
};