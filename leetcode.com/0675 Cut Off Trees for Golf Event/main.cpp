#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int di[] = {0, 0, -1, 1};
int dj[] = {-1, 1, 0, 0};

class Solution {
 private:
  int m, n;
  int get_dis(pair<int, int> start, pair<int, int> end,
              vector<vector<int>>& forest) {
    if (start == end) return 0;
    int res = 0;
    vector<vector<bool>> vis(m, vector<bool>(n));
    queue<pair<int, int>> q;
    q.push(start);
    while (!q.empty()) {
      ++res;
      for (int sz = q.size(); sz > 0; --sz) {
        pair<int, int> p = q.front();
        q.pop();
        for (int k = 0; k < 4; ++k) {
          int ni = p.first + di[k];
          int nj = p.second + dj[k];
          if (ni >= 0 && ni < m && nj >= 0 && nj < n && !vis[ni][nj] &&
              forest[ni][nj]) {
            if (ni == end.first && nj == end.second) return res;
            vis[ni][nj] = true;
            q.emplace(ni, nj);
          }
        }
      }
    }
    return -1;
  }

 public:
  //  guaranteed that no two trees have the same height and there is at least
  //  one tree needs to be cut off.
  int cutOffTree(vector<vector<int>>& forest) {
    if (forest[0][0] == 0) return -1;

    m = forest.size();
    n = forest[0].size();
    vector<pair<int, int>> trees;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (forest[i][j] > 1) trees.emplace_back(i, j);
      }
    }
    sort(trees.begin(), trees.end(), [&](pair<int, int>& a, pair<int, int>& b) {
      return forest[a.first][a.second] < forest[b.first][b.second];
    });

    int res = 0;
    pair<int, int> cur = {0, 0};
    for (auto& p : trees) {
      int dis = get_dis(cur, p, forest);
      if (dis == -1) return -1;
      res += dis;
      cur = p;
    }
    return res;
  }
};