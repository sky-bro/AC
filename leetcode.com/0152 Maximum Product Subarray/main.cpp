#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        int global_max = nums[0], cur_pos_max = 0, cur_neg_max = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                cur_pos_max = cur_neg_max = 0;
            } else if (nums[i] > 0) {
                if (!cur_pos_max) cur_pos_max = nums[i];
                else cur_pos_max *= nums[i];
                cur_neg_max *= nums[i];
            } else {
                int tmp = cur_pos_max;
                cur_pos_max = cur_neg_max * nums[i];
                if (!tmp) cur_neg_max = nums[i];
                else cur_neg_max = tmp * nums[i];
            }
            if (cur_pos_max > global_max) global_max = cur_pos_max;
        }
        return global_max;
    }
};