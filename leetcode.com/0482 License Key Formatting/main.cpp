#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
 public:
  string licenseKeyFormatting(string S, int K) {
    int n = S.length(), dash_cnt = count(S.begin(), S.end(), '-');
    string res = "";
    int cur_len = (n - dash_cnt) % K;
    if (cur_len != 0) cur_len = K - cur_len;
    for (int i = 0; i < n; ++i) {
      if (S[i] == '-') continue;
      res.push_back(toupper(S[i]));
      ++cur_len;
      if (cur_len == K) {
        res.push_back('-');
        cur_len = 0;
      }
    }
    res.pop_back();
    return res;
  }
};