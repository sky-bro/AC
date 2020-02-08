#include <iostream>
#include <vector>

using namespace std;

// ref: https://leetcode.com/problems/burst-balloons/discuss/76229/For-anyone-that-is-still-confused-after-reading-all-kinds-of-explanations...
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<vector<int>> dp(n+2, vector<int>(n+2));
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        for (int len = 0; len < n; ++len) {
            for (int i = 1; i + len <= n; ++i) {
                int j = i + len;
                for (int k = i; k <= j; ++k) {
                    dp[i][j] = max(dp[i][j], dp[i][k-1] + dp[k+1][j] + nums[i-1] * nums[k] * nums[j+1]);
                }
            }
        }
        return dp[1][n];
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums = {3, 1, 5, 8};
    cout<<s.maxCoins(nums)<<endl;
    return 0;
}
