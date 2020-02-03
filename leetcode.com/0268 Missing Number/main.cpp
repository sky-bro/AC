#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            result ^= nums[i] ^ i;
        }
        return result;
    }
};