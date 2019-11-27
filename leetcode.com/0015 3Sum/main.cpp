#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int l, r, n = nums.size();
        for (int i = 0; i < n;){
            if (nums[i] > 0) break;
            vector<int> v;
            v.push_back(nums[i]);
            for (l = i + 1, r = n - 1; l < r && l < n - 1 && r > 0; ) {
                if (nums[l] + nums[r] == -nums[i]) {
                    v.push_back(nums[l++]);
                    v.push_back(nums[r--]);
                    res.push_back(v);
                    for (;l < r && nums[l-1] == nums[l];) ++l;
                    for (;r > l && nums[r+1] == nums[r];) --r;

                    v.clear();
                    v.push_back(nums[i]);
                } else if (nums[l] + nums[r] < -nums[i]) {
                    ++l;
                } else {
                    --r;
                }
            }
            ++i;
            for (; i < n && nums[i-1] == nums[i];) ++i;
        }
        return res;
    }
};
