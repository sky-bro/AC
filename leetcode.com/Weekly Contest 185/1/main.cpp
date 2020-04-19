#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string reformat(string s) {
    vector<char> d;
    vector<char> c;
    for (char cc : s) {
      if (cc <= '9')
        d.push_back(cc);
      else
        c.push_back(cc);
    }
    int a = d.size(), b = c.size();
    if (abs(a - b) > 1) return "";
    string res = "";
    if (a > b) {
      res.push_back(d.back());
      d.pop_back();
      while (!c.empty()) {
        res.push_back(c.back());
        c.pop_back();
        res.push_back(d.back());
        d.pop_back();
      }
    } else {
      if (b > a) {
        res.push_back(c.back());
        c.pop_back();
      }
      while (!d.empty()) {
        res.push_back(d.back());
        d.pop_back();
        res.push_back(c.back());
        c.pop_back();
      }
    }
    return res;
  }
};