#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  int h, n;
  bool chk(vector<int>& piles, int k) {
    int i = 0;
    int s = 0;
    for (; i < n; ++i) {
      s += (piles[i] + k - 1) / k;
      if (s > h) break;
    }
    return i == n;
  }

 public:
  int minEatingSpeed(vector<int>& piles, int H) {
    h = H;
    n = piles.size();
    int l = 1, r = *max_element(piles.begin(), piles.end());
    if (H == n) return r;
    while (l < r) {
      int k = (l + r) / 2;
      if (chk(piles, k)) {
        r = k;
      } else {
        l = k + 1;
      }
    }
    return l;
  }
};
