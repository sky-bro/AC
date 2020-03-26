#include <iostream>
#include <vector>

using namespace std;

class Solution {
 private:
  int di[4] = {1, -1, 0, 0};
  int dj[4] = {0, 0, 1, -1};
  int n;
  void dfs(vector<vector<int>>& M, vector<bool>& visited, int i) {
    for (int j = 0; j < n; ++j) {
      if (!visited[j] && M[i][j]) {
        visited[j] = true;
        dfs(M, visited, j);
      }
    }
  }

 public:
  int findCircleNum(vector<vector<int>>& M) {
    n = M.size();
    vector<bool> visited(n);
    int res = 0;
    for (int i = 0; i < n; ++i) {
      if (!visited[i]) {
        visited[i] = true;
        ++res;
        dfs(M, visited, i);
      }
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<vector<int>> M = {
      {1, 0, 0, 1}, {0, 1, 1, 0}, {0, 1, 1, 1}, {1, 0, 1, 1}};
  cout << s.findCircleNum(M) << endl;
  return 0;
}
