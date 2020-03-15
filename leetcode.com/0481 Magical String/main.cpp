#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int magicalString(int n) {
    if (n == 0) return 0;
    int res = 1;
    vector<uint8_t> nums = {1, 2, 2};
    uint8_t next_num = 1;
    for (int cnt_idx = 2; nums.size() < n; ++cnt_idx) {
      if (nums[cnt_idx] == 1) {
        nums.push_back(next_num);
      } else {
        nums.push_back(next_num);
        nums.push_back(next_num);
      }
      if (next_num == 1) {
        res += nums[cnt_idx];
        next_num = 2;
      } else {
        next_num = 1;
      }
    }
    if (nums.size() > n && next_num == 2) --res;
    return res;
  }
};