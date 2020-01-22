#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<vector<int>> dp(2, vector<int>(n));
        dp[1][0] = nums[0];
        for (int i = 1; i < n; ++i) {
            dp[0][i] = max(dp[0][i-1], dp[1][i-1]);
            dp[1][i] = dp[0][i-1] + nums[i];
        }
        return max(dp[0][n-1], dp[1][n-1]);
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {1,2,3,1};
    nums = {4,2,2,4};
    Solution s;
    cout<<s.rob(nums)<<endl;
    return 0;
}
