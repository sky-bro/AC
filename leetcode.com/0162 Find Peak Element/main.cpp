#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        int idx = 0;
        for (; idx < n - 1 && nums[idx] < nums[idx+1]; ++idx);
        if (idx == n - 1) return n - 1;
        return idx;
    }
};