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
  int maximumWealth(vector<vector<int>>& accounts) {
    int res = 0;
    for_each(accounts.begin(), accounts.end(), [&](vector<int>& acc) {
      int sum = accumulate(acc.begin(), acc.end(), 0);
      res = max(res, sum);
    });
    return res;
  }
};
