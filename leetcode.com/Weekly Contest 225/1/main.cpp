#include <bits/stdc++.h>

using namespace std;

static int x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}();
typedef long long ll;

class Solution {
 public:
  string maximumTime(string time) {
    string res = "";
    if (time[0] == '?') {
      if (time[1] == '?') {
        res.append("23");
      } else {
        if (time[1] < '4')
          res.push_back('2');
        else
          res.push_back('1');
        res.push_back(time[1]);
      }
    } else {
      res.push_back(time[0]);
      if (time[1] == '?') {
        if (time[0] == '2')
          res.push_back('3');
        else
          res.push_back('9');
      } else {
        res.push_back(time[1]);
      }
    }
    res.push_back(':');
    if (time[3] == '?') {
      res.push_back('5');
    } else {
      res.push_back(time[3]);
    }
    if (time[4] == '?') {
      res.push_back('9');
    } else {
      res.push_back(time[4]);
    }
    return res;
  }
};
