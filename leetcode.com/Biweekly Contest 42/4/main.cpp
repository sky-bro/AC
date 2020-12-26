#include <bits/stdc++.h>

using namespace std;

static int x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}();
typedef long long ll;

class Solution {
 public:
  int minMoves(vector<int>& nums, int k) {
    if (k == 1) return 0;
    int n = 0;
    vector<ll> pos;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i]) {
        pos.push_back(i - (n++));
      }
    }
    vector<ll> sums(n);
    sums[0] = pos[0];
    for (int i = 1; i < n; ++i) {
      sums[i] = pos[i] + sums[i - 1];
    }
    ll res = INT32_MAX;
    int l = k / 2, r = k - l - 1;
    for (int i = 0; i + k <= n; ++i) {
      int m = i + k / 2;
      // int l = m-i, r = i+k-m;
      ll cur = pos[m] * l - (sums[m - 1] - sums[i] + pos[i]) - pos[m] * r +
               sums[i + k - 1] - sums[m];
      res = min(cur, res);
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> nums = {1, 0, 0, 1, 0, 1};
  int k = 2;
  cout << s.minMoves(nums, k) << endl;
  return 0;
}
