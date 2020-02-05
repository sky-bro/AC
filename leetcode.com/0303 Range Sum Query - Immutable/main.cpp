#include <iostream>
#include <vector>

using namespace std;

class NumArray {
private:
    int n;
    vector<vector<int>> dp;
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        dp.resize(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) dp[0][i] = nums[i];
        for (int len = 1; len < n; ++len) {
            for (int start = 0; start + len < n; ++start) {
                dp[len][start] = dp[len-1][start] + nums[start+len];
            }
        }
    }
    
    int sumRange(int i, int j) {
        return dp[j-i][i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */