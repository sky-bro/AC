#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i_zero = 0, i_nonzero = 0, n = nums.size();
        if (n == 0) return;
        for (; i_zero < n && i_nonzero < n; ) {
            for (; i_zero < n && nums[i_zero]; ++i_zero);
            for (i_nonzero = max(i_zero + 1, i_nonzero); i_nonzero < n && nums[i_nonzero] == 0; ++i_nonzero);
            if (i_nonzero >= n) break;
            swap(nums[i_zero++], nums[i_nonzero++]);
        }
    }
};