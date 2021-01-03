#include <bits/stdc++.h>

using namespace std;

static int x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}();
typedef long long ll;
const int MOD = 1e9 + 7;

class Solution {
 public:
  int countPairs(vector<int>& deliciousness) {
    unordered_map<int, int> mp;
    for (int d : deliciousness) mp[d]++;
    ll res = 0;
    vector<int> d;
    for (int i = 0; i <= 21; ++i) {
      d.push_back(1 << i);
    }
    for (auto& p : mp) {
      int a = p.first;
      for (int s : d) {
        if (a > s) continue;
        int b = s - a;
        if (a == b) {
          res = (res + 1LL * p.second * (p.second - 1) / 2) % MOD;
        } else if (a > b) {
          auto it = mp.find(b);
          if (it != mp.end()) {
            res = (res + 1LL * it->second * p.second) % MOD;
          }
        } else
          break;
      }
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> A = {2160, 1936, 3,    29,    27, 5, 2503, 1593, 2,    0,
                   16,   0,    3860, 28908, 6,  2, 15,   49,   6246, 1946,
                   23,   105,  7996, 196,   0,  2, 55,   457,  5,    3,
                   924,  7268, 16,   48,    4,  0, 12,   116,  2628, 1468};
  cout << s.countPairs(A) << endl;
  A = {0, 0, 1, 1};
  cout << s.countPairs(A) << endl;
  return 0;
}
