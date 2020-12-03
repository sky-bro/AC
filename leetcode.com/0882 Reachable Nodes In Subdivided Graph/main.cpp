#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  int reachableNodes(vector<vector<int>>& edges, int M, int N) {
    vector<vector<int>> G(N);
    int mask = (1 << 12) - 1;
    for (auto& v : edges) {
      G[v[0]].push_back(v[1] | (v[2] << 12));
      G[v[1]].push_back(v[0] | (v[2] << 12));
    }
    vector<vector<int>> dis(N, vector<int>(N, -1));
    priority_queue<pair<int, int>> q;
    q.push(make_pair(M, 0));
    int res = 0;
    vector<bool> vis(N);
    while (!q.empty()) {
      auto p = q.top();
      q.pop();
      if (vis[p.second]) continue;
      vis[p.second] = true;
      ++res;
      for (int v : G[p.second]) {
        int ni = v & mask;
        int len = v >> 12;
        if (dis[ni][p.second] == -1) {
          dis[p.second][ni] = p.first;
          res += min(p.first, len);
          if (p.first > len) {
            q.push(make_pair(p.first - len - 1, ni));
          }
        } else if (dis[ni][p.second] < len) {
          res += min(dis[ni][p.second] + p.first, len) - dis[ni][p.second];
        }
      }
    }
    return res;
  }
};
