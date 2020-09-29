#include <array>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

// ref: Fast BFS Solution (46ms) -- Clear, Detailed Explanation Included
// https://leetcode.com/problems/shortest-path-visiting-all-nodes/discuss/135809/Fast-BFS-Solution-(46ms)-Clear-Detailed-Explanation-Included
class Solution {
 public:
  int shortestPathLength(vector<vector<int>>& graph) {
    int n = graph.size();
    // mask, node, cost
    set<array<int, 3>> vis;
    queue<array<int, 3>> q;
    for (int i = 0; i < n; ++i) {
      q.push({1 << i, i, 0});
      vis.insert({1 << i, i, 0});
    }
    while (!q.empty()) {
      auto t = q.front();
      q.pop();
      if (t[0] == (1 << n) - 1) return t[2];
      for (int next_node : graph[t[1]]) {
        int next_mask = t[0] | (1 << next_node);
        array<int, 3> nt{next_mask, next_node, 0};
        if (!vis.count(nt)) {
          vis.insert(nt);
          nt[2] = t[2] + 1;
          q.push(nt);
        }
      }
    }
    return -1;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<vector<int>> graph = {{1, 2, 3}, {0}, {0}, {0}};
  cout << s.shortestPathLength(graph) << endl;
  return 0;
}
