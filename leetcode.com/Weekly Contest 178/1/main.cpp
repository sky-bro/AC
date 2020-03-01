#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    vector<int> res;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      int cnt = 0;
      for (int j = 0; j < n; ++j) {
        if (nums[j] < nums[i]) ++cnt;
      }
      res.push_back(cnt);
    }
    return res;
  }
};