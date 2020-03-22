#include <iostream>
#include <vector>

using namespace std;

class Solution {
 private:
  int m, n;
  bool dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int i,
           int j) {
    if (i == m - 1 && j == n - 1) return true;
    visited[i][j] = true;
    switch (grid[i][j]) {
      case 1:
        if (j - 1 >= 0 && !visited[i][j - 1] &&
            (grid[i][j - 1] == 4 || grid[i][j - 1] == 6 ||
             grid[i][j - 1] == 1)) {
          return dfs(grid, visited, i, j - 1);
        } else if (j + 1 < n && !visited[i][j + 1] &&
                   (grid[i][j + 1] & 1)) {  // 1 3 5
          return dfs(grid, visited, i, j + 1);
        } else
          return false;
        break;
      case 2:
        if (i - 1 >= 0 && !visited[i - 1][j] &&
            (grid[i - 1][j] == 3 || grid[i - 1][j] == 4 ||
             grid[i - 1][j] == 2)) {
          return dfs(grid, visited, i - 1, j);
        } else if (i + 1 < m && !visited[i + 1][j] &&
                   (grid[i + 1][j] == 5 || grid[i + 1][j] == 6 ||
                    grid[i + 1][j] == 2)) {
          return dfs(grid, visited, i + 1, j);
        } else
          return false;
        break;
      case 3:
        if (j - 1 >= 0 && !visited[i][j - 1] &&
            (grid[i][j - 1] == 4 || grid[i][j - 1] == 6 ||
             grid[i][j - 1] == 1)) {
          return dfs(grid, visited, i, j - 1);
        } else if (i + 1 < m && !visited[i + 1][j] &&
                   (grid[i + 1][j] == 5 || grid[i + 1][j] == 6 ||
                    grid[i + 1][j] == 2)) {
          return dfs(grid, visited, i + 1, j);
        } else
          return false;
        break;
      case 4:
        if (j + 1 < n && !visited[i][j + 1] && (grid[i][j + 1] & 1)) {  // 1 3 5
          if (dfs(grid, visited, i, j + 1)) return true;
        }
        if (i + 1 < m && !visited[i + 1][j] &&
            (grid[i + 1][j] == 5 || grid[i + 1][j] == 6 ||
             grid[i + 1][j] == 2)) {
          return dfs(grid, visited, i + 1, j);
        } else
          return false;
        break;
      case 5:
        if (i - 1 >= 0 && !visited[i - 1][j] &&
            (grid[i - 1][j] == 3 || grid[i - 1][j] == 4 ||
             grid[i - 1][j] == 2)) {
          return dfs(grid, visited, i - 1, j);
        } else if (j - 1 >= 0 && !visited[i][j - 1] &&
                   (grid[i][j - 1] == 4 || grid[i][j - 1] == 6 ||
                    grid[i][j - 1] == 1)) {
          return dfs(grid, visited, i, j - 1);
        } else
          return false;
        break;
      case 6:
        if (i - 1 >= 0 && !visited[i - 1][j] &&
            (grid[i - 1][j] == 3 || grid[i - 1][j] == 4 ||
             grid[i - 1][j] == 2)) {
          return dfs(grid, visited, i - 1, j);
        } else if (j + 1 < n && !visited[i][j + 1] &&
                   (grid[i][j + 1] & 1)) {  // 1 3 5
          if (dfs(grid, visited, i, j + 1)) return true;
        } else
          return false;
        break;

      default:
        break;
    }
    return false;
  }

 public:
  bool hasValidPath(vector<vector<int>> &grid) {
    m = grid.size(), n = grid[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n));
    return dfs(grid, visited, 0, 0);
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  vector<vector<int>> grid = {{2, 4, 3}, {6, 5, 2}};
  cout << s.hasValidPath(grid) << endl;
  return 0;
}
