#include <iostream>
#include <vector>

using namespace std;

class Solution {
 private:
  vector<vector<int>> res;
  int target;
  void dfs(int cur, vector<int>& path, vector<vector<int>>& graph) {
    if (cur == target) {
      res.push_back(path);
      return;
    }

    for (int node : graph[cur]) {
      path.push_back(node);
      dfs(node, path, graph);
      path.pop_back();
    }
  }

 public:
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    res.clear();
    target = graph.size() - 1;
    vector<int> path;
    path.push_back(0);
    dfs(0, path, graph);
    return res;
  }
};
