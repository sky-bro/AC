#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 private:
  vector<int> sums;

 public:
  Solution(vector<int>& w) {
    for (int i : w) sums.push_back(sums.empty() ? i : sums.back() + i);
  }

  int pickIndex() {
    int rd = rand() % sums.back();
    auto it = upper_bound(sums.begin(), sums.end(), rd);
    return it - sums.begin();
    // int l = 0, r = sums.size() - 1;
    // while (l < r) {
    //   int m = (l + r) / 2;
    //   if (sums[m] <= rd)
    //     l = m + 1;
    //   else
    //     r = m;
    // }
    // return l;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */