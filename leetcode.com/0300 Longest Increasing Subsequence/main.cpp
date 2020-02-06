#include <iostream>
#include <vector>

using namespace std;

// ref: https://leetcode.com/problems/longest-increasing-subsequence/discuss/74924/Two-different-solutions-accepted-as-best-4ms-in-C%2B%2B-enclosed-with-a-basic-DP-solution
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        vector<int> collector;
        for(int i = 0; i < nums.size(); ++i)
        {
            auto iter = std::lower_bound(collector.begin(), collector.end(), nums[i]);
            if(iter == collector.end()) collector.push_back(nums[i]);
            else *iter = nums[i];
        }
        return collector.size();
    }
};