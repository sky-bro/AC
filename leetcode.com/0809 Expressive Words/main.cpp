#include <iostream>
#include <vector>

using namespace std;

class Solution {
 private:
  int nS;
  string s;
  bool chk(const string &s, const string &w) {
    int i = 0, j = 0, nW = w.length();
    while (i < nS && j < nW) {
      char c = s[i];
      int len1 = 0, len2 = 0;
      while (i < nS && s[i] == c) {
        ++i;
        ++len1;
      }
      while (j < nW && w[j] == c) {
        ++j;
        ++len2;
      }
      if (len2 == 0 || len2 > len1 || len2 < len1 && len1 < 3) return false;
    }
    return i == nS && j == nW;
  }

 public:
  int expressiveWords(string S, vector<string> &words) {
    s = S;
    nS = s.length();
    int cnt = 0;
    for (string &word : words) {
      cnt += chk(S, word);
    }
    return cnt;
  }
};
