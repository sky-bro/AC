#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int start, end, n;
        n = nums.size();
        vector<string> result;
        for (int i = 0; i < n;) {
            int j = i + 1;
            for (; j < n; ++j) {
                if (nums[j] != nums[j-1] + 1) break;
            }
            if (i + 1 == j) {
                result.push_back(to_string(nums[i]));
            } else {
                result.push_back(to_string(nums[i]) + "->" + to_string(nums[j-1]));
            }
            i = j;
        }
        return result;
    }
};