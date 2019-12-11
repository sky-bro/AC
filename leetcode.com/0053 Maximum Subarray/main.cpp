#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT32_MIN, partial_sum = 0;
        for (int num: nums) {
            max_sum = max(max_sum, partial_sum += num);
            if (partial_sum < 0) partial_sum = 0;
        }
        return max_sum;
    }
};