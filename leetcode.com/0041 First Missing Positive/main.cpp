#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0, j = 1, n = nums.size();
        for (; i < n && nums[i] <= 0; ++i);
        for (; j + i - 1 < n && nums[j + i - 1] == j; ++j) {
            for (;j + i < n && nums[j + i - 1] == nums[j + i]; ++i);
        }
        return j;
    }
};