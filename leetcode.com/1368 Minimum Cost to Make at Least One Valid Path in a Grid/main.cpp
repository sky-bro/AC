#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int i, j, cost;
  bool operator<(const Node& other) const { return cost > other.cost; }
  Node(int _i, int _j, int _cost) : i(_i), j(_j), cost(_cost) {}
};

class Solution {
 private:
  int m, n;

 public:
  int minCost(vector<vector<int>>& grid) {
    m = grid.size();
    n = grid[0].size();
    priority_queue<Node> q;
    q.emplace(0, 0, 0);
    int diff_i[4] = {0, 0, 1, -1};
    int diff_j[4] = {1, -1, 0, 0};
    vector<vector<int>> dp(m, vector<int>(n, INT32_MAX));
    dp[0][0] = 0;
    while (!q.empty()) {
      Node node = q.top();
      q.pop();
      if (node.i == m - 1 && node.j == n - 1) return node.cost;
      for (int i = 0; i < 4; ++i) {
        int next_i = node.i + diff_i[i];
        int next_j = node.j + diff_j[i];
        if (next_i < 0 || next_i >= m || next_j < 0 || next_j >= n) continue;
        int next_cost = node.cost + (grid[node.i][node.j] != i + 1);
        if (dp[next_i][next_j] <= next_cost) continue;
        dp[next_i][next_j] = next_cost;
        q.emplace(next_i, next_j, next_cost);
      }
    }
    return -1;  // no use
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<vector<int>> grid = {
      {1, 1, 1, 1}, {2, 2, 2, 2}, {1, 1, 1, 1}, {2, 2, 2, 2}};
  cout << s.minCost(grid) << endl;
  return 0;
}
