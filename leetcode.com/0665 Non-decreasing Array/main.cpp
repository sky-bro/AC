#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
      bool found = false;
      int pre = INT32_MIN, n = nums.size();
        for (int i = 1;  i < n; ++i) {
          if (nums[i] < nums[i-1]) {
            if (found) return false;
            found = true;
            if (nums[i] >= pre) {
              // decrease nums[i-1] to pre
              // do nothing
            } else {
              // increase nums[i] to nums[i-1]
              nums[i] = nums[i-1];
            }
          }
          pre = nums[i-1];
        }
        return true;
    }
};