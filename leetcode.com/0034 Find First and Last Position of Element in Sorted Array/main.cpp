#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // vector<int> searchRange(vector<int>& nums, int target) {
    //     vector<int> result(2, -1);
    //     auto plower = lower_bound(nums.begin(), nums.end(), target);
    //     if (plower != nums.end() && *plower == target) {
    //         result[0] = plower - nums.begin();
    //         auto pupper = upper_bound(plower, nums.end(), target);
    //         if (*(pupper-1) == target)
    //             result[1] = pupper-nums.begin()-1;
    //         // bellow is O(n), not good
    //         // for (result[1]=result[0]; result[1] < nums.size() && nums[result[1]] == target; result[1]++);
    //         // result[1]--;
    //     }
    //     return result;
    // }

    vector<int> searchRange(vector<int>& nums, int target) {
        auto iter = equal_range(nums.begin(), nums.end(), target); // iter contains an iterator to the first element equal
		// to target, and one past the second element equal to target.
		// If target doesn't exist, both point to end.
		// If one of the values exist, first will point to the value, second will point one past the value.
		// Think of this as lower_bound and upper_bound combined into one.
        if (iter.first == iter.second) return {-1, -1};
        return {iter.first - begin(nums), iter.second - begin(nums) - 1}; // Minus begin(nums) to get the index of each
    }
};

