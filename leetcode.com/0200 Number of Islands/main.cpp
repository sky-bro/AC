#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int m, n;
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j) {
        if (grid[i][j] == '0') return;
        if (i - 1 >= 0 && !visited[i-1][j]) {
            visited[i-1][j] = true;
            dfs(grid, visited, i-1, j);
        }
        if (i + 1 < m && !visited[i+1][j]) {
            visited[i+1][j] = true;
            dfs(grid, visited, i+1, j);
        }
        if (j - 1 >= 0 && !visited[i][j-1]) {
            visited[i][j-1] = true;
            dfs(grid, visited, i, j-1);
        }
        if (j + 1 < n && !visited[i][j+1]) {
            visited[i][j+1] = true;
            dfs(grid, visited, i, j+1);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size(); if (m == 0) return 0;
        n = grid[0].size(); if (n == 0) return 0;
        vector<vector<bool>> visited(m, vector<bool>(n));
        int result = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (visited[i][j]) continue;
                visited[i][j] = true;
                if (grid[i][j] == '0') continue;
                dfs(grid, visited, i, j);
                ++result;
            }
        }
        return result;
    }
};