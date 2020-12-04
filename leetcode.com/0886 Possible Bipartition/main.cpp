#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// 这题就是判断是不是二分图
// 二分图 Bipartite Graph <=> G至少有两个顶点，且其所有回路的长度均为偶数

class Solution {
 public:
  bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
    vector<int> vis(N, 0);
    vector<vector<int>> G(N);
    for (auto& v : dislikes) {
      G[v[0]-1].push_back(v[1]-1);
      G[v[1]-1].push_back(v[0]-1);
    }
    for (int i = 0; i < N; ++i) {
      if (vis[i]) continue;
      vis[i] = 1;
      stack<int> stk;  // node, color (1/2)
      stk.push(i);
      while (!stk.empty()) {
        int x = stk.top();
        stk.pop();
        for (int y : G[x]) {
          if (vis[y]) {
            if (vis[y] == vis[x]) return false;
          } else {
            vis[y] = vis[x] == 1 ? 2 : 1;
            stk.push(y);
          }
        }
      }
    }
    return true;
  }
};
