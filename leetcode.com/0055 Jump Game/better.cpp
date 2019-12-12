#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int range = 0;
        
        int i = 0;
        for (; i < nums.size(); ++i) {
            --range;
            range = max(range, nums[i]);
            if (range == 0) break;
        }
        
        return i+1 >= nums.size();
    }
};