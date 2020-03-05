#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> findAnagrams(string s, string p) {
    vector<int> res;
    int n = s.length(), m = p.length();
    if (m > n) return res;
    int i = 0;
    int cnt[26]{};
    int zero_cnt = 26;
    for (; i < m; ++i) {
      if (--cnt[s[i] - 'a'] == 0)
        ++zero_cnt;
      else if (cnt[s[i] - 'a'] == -1)
        --zero_cnt;
      if (++cnt[p[i] - 'a'] == 0)
        ++zero_cnt;
      else if (cnt[p[i] - 'a'] == 1)
        --zero_cnt;
    }
    if (zero_cnt == 26) res.push_back(0);

    for (; i < n; ++i) {
      if (--cnt[s[i] - 'a'] == 0)
        ++zero_cnt;
      else if (cnt[s[i] - 'a'] == -1)
        --zero_cnt;
      if (++cnt[s[i - m] - 'a'] == 0)
        ++zero_cnt;
      else if (cnt[s[i - m] - 'a'] == 1)
        --zero_cnt;
      if (zero_cnt == 26) res.push_back(i - m + 1);
    }
    return res;
  }
};