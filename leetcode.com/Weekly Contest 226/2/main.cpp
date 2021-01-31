#include <bits/stdc++.h>

using namespace std;

static int x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}();
typedef long long ll;

class Solution {
 public:
  vector<int> restoreArray(vector<vector<int>> &adjacentPairs) {
    int n = adjacentPairs.size() + 1;
    unordered_map<int, vector<int>> adj;
    for (auto &v : adjacentPairs) {
      adj[v[0]].push_back(v[1]);
      adj[v[1]].push_back(v[0]);
    }
    int x;
    for (auto &p : adj) {
      if (p.second.size() == 1) {
        x = p.first;
        break;
      }
    }
    vector<int> res(n);
    res[0] = x;
    unordered_set<int> vis;
    vis.insert(x);
    for (int i = 1; i < n; ++i) {
      res[i] = vis.count(adj[x][0]) ? adj[x][1] : adj[x][0];
      vis.insert(x = res[i]);
    }
    return res;
  }
};
