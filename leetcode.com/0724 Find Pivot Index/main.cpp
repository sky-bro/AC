#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return -1;
        else if (n == 1) return 0;
        for (int i = 1; i < n; ++i) {
          nums[i] += nums[i-1];
        }
        if (nums[n-1]-nums[0] == 0) return 0;
        for (int i = 1; i < n; ++i) {
          if (nums[i-1] == nums[n-1]-nums[i]) return i;
        }
        return -1;
    }
};
