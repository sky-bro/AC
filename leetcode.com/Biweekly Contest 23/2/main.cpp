#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool canConstruct(string s, int k) {
    int n = s.length();
    if (k > n) return false;
    bool is_odd[26]{};
    for (char c : s) is_odd[c - 'a'] ^= true;
    int odd_cnt = 0;
    for (int i = 0; i < 26; ++i) {
      odd_cnt += is_odd[i];
    }
    k -= odd_cnt;
    if (k < 0) return false;
    return true;
  }
};