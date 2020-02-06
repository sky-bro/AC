#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return n;
        }
        vector<int> dp (n,0);
        dp[0] = nums[0];
        int len = 1;
        for (int i = 1; i < n; i++) {
            auto idx = lower_bound(dp.begin(), dp.begin()+len, nums[i]);
            if (idx == dp.begin() + len) {
                dp[len] = nums[i];
                len++;
            }
            else {
                *idx = nums[i];
            }
        }
        return len;
    }
};