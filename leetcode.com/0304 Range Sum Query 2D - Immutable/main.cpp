#include <iostream>
#include <vector>

using namespace std;

class NumMatrix {
private:
    vector<vector<int>> dp;
    int m, n;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        m = matrix.size(), n = m ? matrix[0].size() : 0;
        dp.resize(m+1,vector<int>(n+1));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i+1][j+1] = dp[i][j+1] - dp[i][j] + dp[i+1][j] + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2+1][col2+1] - dp[row2+1][col1] - dp[row1][col2+1] + dp[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */