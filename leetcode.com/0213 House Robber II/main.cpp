#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 0) return 0;
        else if (n == 1) return nums[0];

        // dp[0][i] 表示从0到i，最多能rob的money，0表示不rob i下标的
        // dp[1][i] 表示从0到i，最多能rob的money，1表示要rob i下标的
        vector<vector<int>> dp(2, vector<int>(n));

        dp[0][0] = 0;
        dp[1][0] = nums[0];
        for (int i = 1; i < n-1; ++i) {
            dp[0][i] = max(dp[0][i-1], dp[1][i-1]);
            dp[1][i] = dp[0][i-1] + nums[i];
        }
        int max_sum = max(dp[0][n-2], dp[1][n-2]);

        dp[0][1] = 0;
        dp[1][1] = nums[1];
        for (int i = 2; i < n; ++i) {
            dp[0][i] = max(dp[0][i-1], dp[1][i-1]);
            dp[1][i] = dp[0][i-1] + nums[i];
        }
        int max_sum2 = max(dp[0][n-1], dp[1][n-1]);

        return max(max_sum, max_sum2);
    }
};