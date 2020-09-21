#include <iostream>
#include <vector>

using namespace std;

class Solution {
 private:
  int n;
  bool dfs(int i, const string &S, vector<int> &cur, int sz) {
    if (i == n) return true;
    for (int len = 1; i + len <= n; ++len) {
      if (S[i] == '0' && len != 1) break;
      long c = atol(S.substr(i, len).c_str());
      if (c > INT32_MAX) break;
      if (c == 0L + cur[sz - 1] + cur[sz - 2]) {
        cur.push_back(c);
        if (dfs(i + len, S, cur, sz + 1)) return true;
        cur.pop_back();
      }
    }
    return false;
  }

 public:
  vector<int> splitIntoFibonacci(string S) {
    n = S.size();
    vector<int> cur;
    for (int i = 0; i < n - 2; ++i) {
      if (S[0] == '0' && i != 0) break;
      long a = atol(S.substr(0, i + 1).c_str());
      if (a > INT32_MAX) break;
      cur.push_back(a);
      for (int j = i + 1; j < n - 1; ++j) {
        if (S[i + 1] == '0' && j - i != 1) break;
        long b = atol(S.substr(i + 1, j - i).c_str());
        if (b > INT32_MAX) break;
        cur.push_back(b);
        if (dfs(j + 1, S, cur, 2)) return cur;
        cur.pop_back();
      }
      cur.pop_back();
    }
    return {};
  }
};
