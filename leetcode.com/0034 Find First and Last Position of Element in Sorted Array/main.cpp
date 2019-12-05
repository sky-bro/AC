#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2, -1);
        auto plower = lower_bound(nums.begin(), nums.end(), target);
        if (plower != nums.end() && *plower == target) {
            result[0] = plower - nums.begin();
            auto pupper = upper_bound(plower, nums.end(), target);
            if (*(pupper-1) == target)
                result[1] = pupper-nums.begin()-1;
            // bellow is O(n), not good
            // for (result[1]=result[0]; result[1] < nums.size() && nums[result[1]] == target; result[1]++);
            // result[1]--;
        }
        return result;
    }
};

