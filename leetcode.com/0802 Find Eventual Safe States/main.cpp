#include <iostream>
#include <vector>

using namespace std;

// ref: Detect Cycle in a directed graph using colors
// https://www.geeksforgeeks.org/detect-cycle-direct-graph-using-colors/

class Solution {
  enum Color { UNCHKED, SAFE, UNSAFE };
  int n;
  bool is_safe(int i, vector<Color>& colors, vector<vector<int>>& graph) {
    if (colors[i]) return colors[i] == SAFE;
    colors[i] = UNSAFE;
    for (int j : graph[i]) {
      if (!is_safe(j, colors, graph)) return false;
    }
    colors[i] = SAFE;
    return true;
  }

 public:
  vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    n = graph.size();
    vector<int> res;
    vector<Color> colors(n);  // all unchked
    for (int i = 0; i < n; ++i) {
      if (is_safe(i, colors, graph)) res.push_back(i);
    }
    return res;
  }
};
