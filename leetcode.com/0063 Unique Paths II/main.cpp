#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<long> dp(n);
        for (int i = n - 1; i >= 0 && !obstacleGrid[m-1][i]; dp[i--] = 1);
        for (int i = m-2; i >= 0; --i) {
            if (obstacleGrid[i][n-1]) dp[n-1] = 0;
            for (int j = n-2; j >= 0; --j) {
                if (obstacleGrid[i][j]) {
                    dp[j] = 0;
                } else {
                    dp[j] += dp[j+1];
                }
            }
        }
        return dp[0];
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> grid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0},
    };
    vector<vector<int>> grid2 = {
        {0},
        {1},
    };
    Solution s;
    cout<<s.uniquePathsWithObstacles(grid2)<<endl;
    return 0;
}
