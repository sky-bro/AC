#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    //
    int trap(vector<int>& height) {
        int res = 0, mx = 0, n = height.size();     //<-- mx存目前最高
        vector<int> dp(n, 0);
        for (int i = 0; i < n; ++i) {
            dp[i] = mx;                             //左->右, dp[i]存到i-1之前最高的值
            mx = max(mx, height[i]);                //左->右, 目前最高的值
        }
        mx = 0;
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = min(dp[i], mx);                 //右->左, dp[i]存，左到右中到i這個位置時最高的值，和右到左到i這個位置時的最高值相比
                                                    //較小者，e.g. dp[9] = min(3, 2) = 2
            mx = max(mx, height[i]);                //右->左, 目前最高的值
            if (dp[i] > height[i]) res += dp[i] - height[i];
        }
        return res;
    }
};
