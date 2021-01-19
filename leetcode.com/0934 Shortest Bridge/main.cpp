#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

bool vis[10000];
int di[4] = {0, 0, 1, -1};
int dj[4] = {1, -1, 0, 0};

class Solution {
 private:
  int m, n;

 public:
  int shortestBridge(vector<vector<int>>& A) {
    m = A.size(), n = A[0].size();
    fill(vis, vis + m * n, 0);
    stack<int> stk;  // dfs, add nodes of first island
    queue<int> q;    // bfs, shortest distance to the other island
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (A[i][j]) {
          int idx = i * n + j;
          vis[idx] = true;
          q.push(idx);
          stk.push(idx);
          goto ok;
        }
      }
    }
  ok:;
    while (!stk.empty()) {
      int idx = stk.top();
      stk.pop();
      for (int k = 0; k < 4; ++k) {
        int ni = idx / n + di[k], nj = idx % n + dj[k];
        int nidx = ni * n + nj;
        if (ni >= 0 && ni < m && nj >= 0 && nj < n && A[ni][nj] && !vis[nidx]) {
          vis[nidx] = true;
          q.push(nidx);
          stk.push(nidx);
        }
      }
    }
    int res = -1;
    while (!q.empty()) {
      ++res;
      for (int sz = q.size(); sz; --sz) {
        int idx = q.front();
        q.pop();
        for (int k = 0; k < 4; ++k) {
          int ni = idx / n + di[k], nj = idx % n + dj[k];
          int nidx = ni * n + nj;
          if (ni >= 0 && ni < m && nj >= 0 && nj < n && !vis[nidx]) {
            if (A[ni][nj]) goto found;
            vis[nidx] = true;
            q.push(nidx);
          }
        }
      }
    }
  found:
    return res;
  }
};
