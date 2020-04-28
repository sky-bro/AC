#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int idx = nums.size()-1;
        for (int i = idx-1; i >= 0; --i) {
          if (nums[i] > nums[idx]) idx = i;
        }
        return any_of(nums.begin(), nums.end(), [&](int num){
          return nums[idx] != num && nums[idx] < num * 2;
        }) ? -1 : idx;
    }
};
