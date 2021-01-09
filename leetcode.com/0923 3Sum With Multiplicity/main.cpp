#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
int d[] = {1, 2, 6};

class Solution {
 public:
  int threeSumMulti(vector<int>& arr, int target) {
    vector<ll> cnt(101);
    for (int x : arr) cnt[x]++;
    ll res = 0;
    for (int i = 0; i <= 100 && i * 3 <= target; ++i) {
      if (cnt[i] == 0) continue;
      ll a = cnt[i]--;
      for (int j = i; j <= 100 && i + j * 2 <= target; ++j) {
        if (cnt[j] == 0) continue;
        ll b = cnt[j]--;
        int k = target - i - j;
        if (k <= 100 && cnt[k]) {
          ll cur = a * b * cnt[k];
          int r = (i == j) + (j == k);
          res = (res + cur / d[r] % MOD) % MOD;
        }
        ++cnt[j];
      }
      ++cnt[i];
    }
    return res;
  }
};
