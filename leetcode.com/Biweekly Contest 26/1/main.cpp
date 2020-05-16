#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPower(string s) {
        int n = s.length();
        int res = 1;
        for (int i = 0; i < n;) {
          char c = s[i];
          int cur = 0;
          while (i < n && s[i] == c) {++cur; ++i;}
          if (cur > res) res = cur;
        }
        return res;
    }
};
