#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int leastInterval(vector<char>& tasks, int n) {
    int sz = tasks.size();
    int cnt[26]{};
    for (char c : tasks) cnt[c - 'A']++;
    int max_cnt = 0, max_cnt_cnt = 0;
    for (int i = 0; i < 26; ++i) {
      if (cnt[i] == max_cnt)
        max_cnt_cnt++;
      else if (cnt[i] > max_cnt) {
        max_cnt = cnt[i];
        max_cnt_cnt = 1;
      }
    }
    return max((max_cnt - 1) * (n + 1) + max_cnt_cnt, sz);
  }
};