#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int n, d;
    int _maxJumps(vector<int> &arr, int idx, vector<int> &dp) {
        if (dp[idx] != 0) return dp[idx];
        int result = 1;
        for (int i = idx-1; i >= 0 && idx - i <= d && arr[idx] > arr[i]; --i) {
            result = max(result, _maxJumps(arr, i, dp) + 1);
        }

        for (int i = idx+1; i < n && i - idx <= d && arr[idx] > arr[i]; ++i) {
            result = max(result, _maxJumps(arr, i, dp) + 1);
        }
        return dp[idx] = result;
    }

public:
    int maxJumps(vector<int>& arr, int d) {
        n = arr.size();
        this->d = d;
        if (n == 0) return 0;
        vector<int> dp(n);
        int result = 1;
        for (int i = 0; i < n; ++i) {
            result = max(result, _maxJumps(arr, i, dp));
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {6,4,14,6,8,13,9,7,10,6,12};
    int d = 2;
    Solution s;
    cout<<s.maxJumps(nums, d)<<endl;
    return 0;
}
