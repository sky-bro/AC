#include <cctype>
#include <iostream>
#include <vector>

using namespace std;

// ref:
// https://leetcode.com/problems/number-of-segments-in-a-string/discuss/91638/O(n)-sentinel-value-concise-solution-C%2B%2B
class Solution {
 public:
  int countSegments(string s) {
    int res = 0;
    s.push_back(' ');
    for (int i = 1; i < s.size(); ++i)
      if (s[i] == ' ' && s[i - 1] != ' ') ++res;
    return res;
  }
};