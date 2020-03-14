#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int totalHammingDistance(vector<int>& nums) {
    int res = 0, ones, sz = nums.size();
    for (int i = 0; i <= 30; ++i) {
      ones = 0;
      for (int num : nums) {
        ones += (num >> i) & 1;
      }
      res += (sz - ones) * ones;
    }
    return res;
  }
};

class Solution2 {
 public:
  int totalHammingDistance(vector<int>& nums) {
    int res = 0;
    for (int i = 0; i <= 30; i += 2) {
      int cnt[4]{};
      for (int num : nums) {
        cnt[(num >> i) & 3]++;
      }
      res += (cnt[1] + cnt[2]) * (cnt[0] + cnt[3]) +
             2 * (cnt[1] * cnt[2] + cnt[0] * cnt[3]);
    }
    return res;
  }
};