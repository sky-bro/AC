#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  string generateTheString(int n) {
    string res = "";
    if (n & 1) {
      for (; n; --n) res.push_back('a');
    } else {
      res.push_back('a');
      for (--n; n; --n) res.push_back('b');
    }
    return res;
  }
};