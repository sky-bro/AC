#include <algorithm>s
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  string convertToBase7(int num) {
    if (num == 0) return "0";
    string res = "";
    bool isPositive = true;
    if (num < 0) {
      num = -num;
      isPositive = false;
    }
    while (num) {
      int r = num % 7;
      num /= 7;
      res.push_back(r + '0');
    }
    if (!isPositive) res.push_back('-');
    reverse(res.begin(), res.end());
    return res;
  }
};