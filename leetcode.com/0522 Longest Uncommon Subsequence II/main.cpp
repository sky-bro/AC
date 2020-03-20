#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 private:
  bool is_subsquence(const string& a, const string& b) {
    int len_a = a.length(), len_b = b.length();
    if (len_a < len_b) return false;
    int i = 0, j = 0;
    while (i <= len_a - (len_b - j) && j < len_b)
      if (a[i++] == b[j]) ++j;
    return j == len_b;
  }

 public:
  int findLUSlength(vector<string>& strs) {
    unordered_map<string, int> m;
    int max_len = 0;
    for (const string& str : strs) {
      int len = str.length();
      if (len > max_len) {
        max_len = len;
      }
      m[str]++;
    }
    int res = -1;
    for (auto it = m.begin(); it != m.end(); ++it) {
      if (it->second > 1) continue;
      int cur_len = it->first.length();
      if (cur_len == max_len) return max_len;
      auto it0 = m.begin();
      for (; it0 != m.end(); ++it0) {
        if (it0 == it) continue;
        if (is_subsquence(it0->first, it->first)) break;
      }
      if (it0 == m.end() && cur_len > res) res = cur_len;
    }
    return res;
  }
};