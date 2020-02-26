#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// this is a graph problem
class Solution {
 private:
  unordered_map<string, unordered_map<string, double>> G;
  unordered_map<string, bool> visited;
  double dfs(const string& start, const string& end, double cur_res) {
    visited[start] = true;
    if (start == end) return cur_res;
    auto& edges = G[start];
    for (auto it = edges.begin(); it != edges.end(); ++it) {
      if (visited[it->first]) continue;
      double tmp = dfs(it->first, end, cur_res * it->second);
      if (tmp != -1.0) return tmp;
    }

    return -1.0;
  }

 public:
  vector<double> calcEquation(vector<vector<string>>& equations,
                              vector<double>& values,
                              vector<vector<string>>& queries) {
    vector<double> result;
    G.clear();
    int n = equations.size();
    for (int i = 0; i < n; ++i) {
      G[equations[i][0]][equations[i][1]] = values[i];
      G[equations[i][1]][equations[i][0]] = 1.0 / values[i];
      visited[equations[i][0]] = false;
      visited[equations[i][1]] = false;
    }
    for (auto& vi : queries) {
      for (auto it = visited.begin(); it != visited.end(); ++it)
        it->second = false;

      if (visited.find(vi[0]) == visited.end() ||
          visited.find(vi[1]) == visited.end()) {
        result.push_back(-1.0);
      } else {
        result.push_back(dfs(vi[0], vi[1], 1.0));
      }
    }
    return result;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<vector<string>> equations = {{"a", "b"}, {"b", "c"}};
  vector<double> values = {2.0, 3.0};
  vector<vector<string>> queries = {
      {"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};
  s.calcEquation(equations, values, queries);
  return 0;
}
