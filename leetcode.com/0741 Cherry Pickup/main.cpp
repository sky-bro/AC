// ref: Step by step guidance of the O(N^3) time and O(N^2) space solution
// https://leetcode.com/problems/cherry-pickup/discuss/109903/Step-by-step-guidance-of-the-O(N3)-time-and-O(N2)-space-solution
// ref: official solution: 741. Cherry Pickup
// https://leetcode.com/articles/cherry-pickup/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int N = grid.size();
        vector<vector<int>> dp(N, vector<int>(N));
        dp[0][0] = grid[0][0];
        for (int n = 1; n <= 2*(N - 1); ++n) {
            for (int r1 = N-1; r1 >= 0; --r1) {
                for (int r2 = N-1; r2 >= 0; --r2) {
                    int c1 = n - r1, c2 = n - r2;
                    if (c1 < 0 || c1 >= N || c2 < 0 || c2 >= N || grid[r1][c1] < 0 || grid[r2][c2] < 0) {
                        dp[r1][r2] = -1;
                        continue;
                    }
                    if (r1 > 0) dp[r1][r2] = max(dp[r1][r2], dp[r1-1][r2]);
                    if (r2 > 0) dp[r1][r2] = max(dp[r1][r2], dp[r1][r2-1]);
                    if (r1 > 0 && r2 > 0) dp[r1][r2] = max(dp[r1][r2], dp[r1-1][r2-1]);
                    if (dp[r1][r2] >= 0) dp[r1][r2] += grid[r1][c1] + (r1 == r2 ? 0 : grid[r2][c2]);
                }
            }
        }
        return ~dp[N-1][N-1] ? dp[N-1][N-1] : 0;
    }
};
