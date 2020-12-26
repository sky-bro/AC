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
  double averageWaitingTime(vector<vector<int>>& customers) {
    double sum = 0;
    int n = customers.size();
    int t = 0;
    for (auto& v : customers) {
      if (v[0] >= t) {
        sum += v[1];
        t = v[0] + v[1];
      } else {
        sum += v[1] + (t - v[0]);
        t += v[1];
      }
    }
    return sum / n;
  }
};
