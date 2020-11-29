#include <bits/stdc++.h>

using namespace std;

static int x = []() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}();
typedef long long ll;

class Solution {
 public:
  vector<int> mostCompetitive(vector<int>& nums, int k) {
    vector<int> res;
    res.push_back(nums[0]);
    int n = nums.size();
    int i = 1;
    int len = 1;
    for (; i < n; ++i) {
      auto it =
          upper_bound(res.begin() + max(k - (n - i), 0), res.end(), nums[i]);
      if (it == res.end()) {
        if (res.size() < k) {
          res.push_back(nums[i]);
        }
      } else {
        int sz = it - res.begin();
        res[sz] = nums[i];
        res.resize(sz + 1);
      }
    }
    return res;
  }
};
