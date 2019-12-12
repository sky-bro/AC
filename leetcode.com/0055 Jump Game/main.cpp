#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int index = 0, n = nums.size();
        while (true) {
            if (nums[index] + index >= n-1) return true;
            int max_idx = index, next_idx = index;
            for (int i = 1; i <= nums[index]; ++i) {
                if (nums[i+index] + i + index >= n - 1) return true;
                if (nums[i+index] + i + index > max_idx) {
                    max_idx = nums[i+index] + i + index;
                    next_idx = i + index;
                }
            }
            if (next_idx == index) return false;
            else index = next_idx;
        }
    }
};