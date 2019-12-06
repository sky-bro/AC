#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// time: O(n), space: O(n)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size(), i;
        vector<bool> _nums(n, false);
        for (auto x: nums) {
            if (x <= n && x > 0) _nums[x-1] = true;
        }
        for (i = 0; i < n && _nums[i]; ++i);
        return i+1;
    }
};

// time: O(nlogn)
// class Solution {
// public:
//     int firstMissingPositive(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         int i = 0, j = 1, n = nums.size();
//         for (; i < n && nums[i] <= 0; ++i);
//         for (; j + i - 1 < n && nums[j + i - 1] == j; ++j) {
//             for (;j + i < n && nums[j + i - 1] == nums[j + i]; ++i);
//         }
//         return j;
//     }
// };