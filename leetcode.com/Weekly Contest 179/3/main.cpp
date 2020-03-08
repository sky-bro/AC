#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 private:
  int dfs(vector<vector<int>>& G, vector<int>& informTime, int headID) {
    int res = G[headID].empty() ? 0 : informTime[headID];
    int max_time = 0;
    for (int id : G[headID]) {
      max_time = max(max_time, dfs(G, informTime, id));
    }
    return res + max_time;
  }

 public:
  int numOfMinutes(int n, int headID, vector<int>& manager,
                   vector<int>& informTime) {
    vector<vector<int>> G(n, vector<int>());
    for (int i = 0; i < n; ++i) {
      if (manager[i] == -1) continue;
      G[manager[i]].push_back(i);
    }
    return dfs(G, informTime, headID);
  }
};
