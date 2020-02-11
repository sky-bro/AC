#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
    int m, n;
    int dfs(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& lengths) {
        if (lengths[i][j]) return lengths[i][j];

        int cur_len = 0, tmp_len = 0;
        if (i-1 >= 0 && matrix[i-1][j] > matrix[i][j]) {
            cur_len = max(cur_len, dfs(matrix, i-1, j, lengths));
        }
        if (j-1 >= 0 && matrix[i][j-1] > matrix[i][j]) {
            cur_len = max(cur_len, dfs(matrix, i, j-1, lengths));
        }
        if (i+1 < m && matrix[i+1][j] > matrix[i][j]) {
            cur_len = max(cur_len, dfs(matrix, i+1, j, lengths));
        }
        if (j+1 < n && matrix[i][j+1] > matrix[i][j]) {
            cur_len = max(cur_len, dfs(matrix, i, j+1, lengths));
        }

        return lengths[i][j] = cur_len + 1;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        if (m == 0) return 0;
        n = matrix[0].size();
        if (n == 0) return 0;
        int result = 1;
        vector<vector<int>> lengths(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (lengths[i][j]) continue;
                dfs(matrix, i, j, lengths);
                result = max(result, lengths[i][j]);
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> matrix = {{9,9,4},{6,6,8},{2,1,1}};
    cout<<s.longestIncreasingPath(matrix)<<endl;

    matrix = {{3,4,5},{3,2,6},{2,2,1}};
    cout<<s.longestIncreasingPath(matrix)<<endl;
    return 0;
}
