#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        int res = s[0] == '0';
        for (int i = 1; i < n; ++i) {
          if (s[i] == '1') ++res;
        }
        int cur = res;
        for (int i = 1; i < n-1; ++i) {
          if (s[i] == '0') ++cur;
          else --cur;
          res = max(res, cur);
        }
        return res;
    }
};
