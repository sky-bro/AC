#include <bits/stdc++.h>
using namespace std;
int __fastio = []() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } ();

typedef long long ll;

class Solution {
 public:
  int brokenCalc(ll s, ll t) {
    int res = 0;
    while (s < t) {
      if (t & 1) {
        t = (t + 1) / 2;
        res += 2;
      } else {
        t >>= 1;
        ++res;
      }
    }
    res += s - t;
    return res;
  }
};

