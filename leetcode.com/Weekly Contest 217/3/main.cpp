#include <bits/stdc++.h>

using namespace std;

static int x = []() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}();
typedef long long ll;

int d[200100];

class Solution {
 public:
  int minMoves(vector<int>& nums, int limit) {
    memset(d, 0, sizeof(d));
    int n = nums.size();
    for (int i = 0; i < n / 2; ++i) {
      int l = 1 + min(nums[i], nums[n - i - 1]);
      int r = limit + max(nums[i], nums[n - i - 1]);
      int m = nums[i] + nums[n - i - 1];
      d[l] += -1;
      d[r + 1] += 1;
      d[m] += -1;
      d[m + 1] += 1;
    }
    int res = n;
    int cur = n;
    for (int i = 2; i < limit * 2 + 2; ++i) {
      cur += d[i];
      res = min(res, cur);
    }
    return res;
  }
};
