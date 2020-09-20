#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

class Solution {
 public:
  int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
    int n = nums.size();
    vector<int> cnts(n);
    for (auto& req : requests) {
      cnts[req[0]] += 1;
      if (req[1] + 1 < n) cnts[req[1] + 1] -= 1;
    }
    for (int i = 1; i < n; ++i) {
      cnts[i] += cnts[i - 1];
    }
    sort(cnts.begin(), cnts.end());
    sort(nums.begin(), nums.end());
    long long res = 0;
    for (int i = 0; i < n; ++i) {
      res = (res + nums[i] * cnts[i]) % MOD;
    }
    return res;
  }
};
