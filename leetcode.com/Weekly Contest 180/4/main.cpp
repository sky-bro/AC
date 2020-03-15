#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int MOD = 1000000000 + 7;
typedef unsigned long long ULL;
class Solution {
 public:
  int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency,
                     int k) {
    vector<pair<int, int>> workers;
    for (int i = 0; i < n; ++i) workers.emplace_back(efficiency[i], speed[i]);
    sort(workers.begin(), workers.end());
    multiset<int> speed_set;
    ULL speed_sum = 0;
    int i = n - k;
    ULL res = 0;
    for (int j = n - 1; j >= n - k; --j) {
      speed_sum += workers[j].second;
      speed_set.insert(workers[j].second);
      res = max(res, speed_sum * workers[j].first);
    }
    for (--i; i >= 0; --i) {
      int cur_eff = workers[i].first;
      auto it = speed_set.begin();
      if (*it < workers[i].second) {
        speed_sum -= *it;
        speed_set.erase(it);
        speed_sum += workers[i].second;
        speed_set.insert(workers[i].second);
        res = max(res, speed_sum * workers[i].first);
      }
    }
    return int(res % MOD);
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  int n = 3;
  vector<int> speed = {2, 8, 2};
  vector<int> eff = {2, 7, 1};
  int k = 2;
  cout << s.maxPerformance(n, speed, eff, k) << endl;
  return 0;
}
