// ref: Python, Simple with Explanation
// https://leetcode.com/problems/find-the-closest-palindrome/discuss/102391/Python-Simple-with-Explanation
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;

class Solution {
 private:
  LL num;
  void update(LL cur_res, LL& res, LL& d) {
    LL cur_d = abs(cur_res - num);
    if (cur_d < d || (cur_d == d && cur_res < res)) {
      res = cur_res;
      d = cur_d;
    }
  }

 public:
  string nearestPalindromic(string n) {
    num = stoll(n);
    int len = n.length();
    LL res = INT64_MAX, d = INT64_MAX;
    LL left_num = stoll(n.substr(0, (len + 1) / 2));
    for (LL base : {pow(10, len), pow(10, len - 1)}) {
      LL cur_res = base - 1;
      if (cur_res != num) update(cur_res, res, d);
      cur_res = base + 1;
      if (cur_res != num) update(cur_res, res, d);
    }
    for (LL base : {left_num, left_num - 1, left_num + 1}) {
      string left = to_string(base);
      string right = left;
      if (len & 1) right.pop_back();
      reverse(right.begin(), right.end());
      LL cur_res = stoll(left + right);
      if (cur_res != num) update(cur_res, res, d);
    }
    return to_string(res);
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  string n;
  while (cin >> n) cout << s.nearestPalindromic(n) << endl;
  return 0;
}
