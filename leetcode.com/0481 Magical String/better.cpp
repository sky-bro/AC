#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int magicalString(int n) {
    if (n == 0) return 0;
    int res = 1;
    vector<uint8_t> nums = {1, 2, 2};
    int cnt_idx = 2;
    for (; nums.size() < n; ++cnt_idx) {
      uint8_t next_num = (cnt_idx & 1) ? 2 : 1;
      nums.push_back(next_num);
      if (nums[cnt_idx] == 2) {
        nums.push_back(next_num);
      }
      if (next_num == 1) res += nums[cnt_idx];
    }
    if (nums.size() > n && (cnt_idx & 1)) --res;
    return res;
  }
};