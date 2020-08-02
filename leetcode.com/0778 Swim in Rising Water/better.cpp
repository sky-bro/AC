#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// C++ two solutions, Binary Search+DFS and Dijkstra+BFS, O(n^2logn), 11ms
// https://leetcode.com/problems/swim-in-rising-water/discuss/113758/C%2B%2B-two-solutions-Binary-Search%2BDFS-and-Dijkstra%2BBFS-O(n2logn)-11ms

class Solution {
 public:
  int swimInWater(vector<vector<int>>& grid) {
    int n = grid.size(), ans = max(grid[0][0], grid[n - 1][n - 1]);
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    vector<vector<int>> visited(n, vector<int>(n, 0));
    visited[0][0] = 1;
    vector<int> dir({-1, 0, 1, 0, -1});
    pq.push({ans, 0, 0});
    while (!pq.empty()) {
      auto cur = pq.top();
      pq.pop();
      ans = max(ans, cur[0]);
      queue<pair<int, int>> myq;
      myq.push({cur[1], cur[2]});
      while (!myq.empty()) {
        auto p = myq.front();
        myq.pop();
        if (p.first == n - 1 && p.second == n - 1) return ans;
        for (int i = 0; i < 4; ++i) {
          int r = p.first + dir[i], c = p.second + dir[i + 1];
          if (r >= 0 && r < n && c >= 0 && c < n && visited[r][c] == 0) {
            visited[r][c] = 1;
            if (grid[r][c] <= ans)
              myq.push({r, c});
            else
              pq.push({grid[r][c], r, c});
          }
        }
      }
    }
    return -1;
  }
};