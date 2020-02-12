#include <iostream>
#include <vector>

using namespace std;

// ref: https://leetcode.com/problems/patching-array/discuss/78488/Solution-%2B-explanation
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long miss_until = 1;
        int added = 0, i = 0;
        while (miss_until <= n) {
            if (i < nums.size() && nums[i] <= miss_until) {
                miss_until += nums[i++];
            } else {
                miss_until <<= 1;
                ++added;
            }
        }
        return added;
    }
};