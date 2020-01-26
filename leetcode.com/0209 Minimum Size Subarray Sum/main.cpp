#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int l = 0, r = 0, n = nums.size();
        if (n == 0) return 0;
        int cur_sum = nums[0], min_len = 0;
        while (true) {
            if (cur_sum < s) {
                if (r == n-1) break;
                cur_sum += nums[++r];
            } else {
                if (min_len == 0 || r - l + 1 < min_len) min_len = r - l + 1;
                cur_sum -= nums[l++];
            }
        }
        return min_len;
    }
};