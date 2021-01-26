#include <iostream>
#include <vector>

using namespace std;

class Solution {
 private:
  vector<int> res;
  int n, k;
  void dfs(int i, int cur, int pre_digit) {
    if (i == n) {
      res.push_back(cur);
      return;
    }
    // -
    int nxt_digit = pre_digit - k;
    if (nxt_digit >= 0) {
      dfs(i + 1, cur * 10 + nxt_digit, nxt_digit);
    }
    // +
    nxt_digit = pre_digit + k;
    if (nxt_digit <= 9) {
      dfs(i + 1, cur * 10 + nxt_digit, nxt_digit);
    }
  }

 public:
  vector<int> numsSameConsecDiff(int n, int k) {
    res.clear();
    this->n = n;
    this->k = k;
    if (k == 0) {
      int base = 1;
      while (--n) base = base * 10 + 1;
      for (int i = 1; i <= 9; ++i) res.push_back(base * i);
      return res;
    }
    for (int i = 1; i <= 9; ++i) {
      dfs(1, i, i);
    }
    return res;
  }
};
