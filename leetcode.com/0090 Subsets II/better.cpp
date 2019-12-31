#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void re_subDup(vector<vector<int>>& res,vector<int>& subset,\
                   vector<int> &nums, int begin)
    {
        res.push_back(subset);
        for(int i = begin; i<nums.size();i++)
        {
            if(i==begin||nums[i]!=nums[i-1])
            {
            subset.push_back(nums[i]);
            re_subDup(res,subset,nums,i+1);
            subset.pop_back();
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.empty())return res;
        sort(nums.begin(),nums.end());
        vector<int> subset;
        re_subDup(res,subset,nums,0);
        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 2, 2};
    Solution s;
    s.subsetsWithDup(nums);
    return 0;
}
