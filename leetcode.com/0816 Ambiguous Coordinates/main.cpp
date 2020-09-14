#include <iostream>
#include <vector>

using namespace std;

class Solution {
 private:
  vector<string> possible_nums(string &s, int i, int n) {
    vector<string> res;
    // case 1: no decimal point
    if (n == 1 || s[i] != '0') res.push_back(s.substr(i, n));
    // case 2: include decimal point
    if (n == 1 || s[i + n - 1] == '0') return res;  // cannot include '.'
    if (s[i] == '0') {                              // can only be "0.xxx"
      res.push_back("0." + s.substr(i + 1, n - 1));
    } else {  // "1xxx1"
      string cur = "";
      for (int j = 1; j < n; ++j) {
        cur.push_back(s[i + j - 1]);
        res.push_back(cur + "." + s.substr(i + j, n - j));
      }
    }
    return res;
  }

 public:
  vector<string> ambiguousCoordinates(string S) {
    vector<string> res;
    int n = S.size();
    for (int len = 1; len < n - 2; ++len) {
      auto X = possible_nums(S, 1, len);
      auto Y = possible_nums(S, 1 + len, n - len - 2);
      for (const string &x : X) {
        for (const string &y : Y) {
          res.push_back("(" + x + ", " + y + ")");
        }
      }
    }
    return res;
  }
};
