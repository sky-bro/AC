#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isBipartite(vector<vector<int>>& graph) {
    int N = graph.size();
    vector<int> vis(N);
    stack<int> stk;
    for (int i = 0; i < N; ++i) {
      if (vis[i]) continue;
      stk.push(i);
      vis[i] = 1;
      while (!stk.empty()) {
        int cur = stk.top();
        stk.pop();
        for (int nxt : graph[cur]) {
          if (vis[nxt]) {
            if (vis[nxt] == vis[cur]) return false;
          } else {
            vis[nxt] = vis[cur] ^ 3;  // 2 -> 1, 1 -> 2
            stk.push(nxt);
          }
        }
      }
    }
    return true;
  }
};
