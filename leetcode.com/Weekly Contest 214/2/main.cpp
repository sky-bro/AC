#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int minDeletions(string s) {
    vector<int> cnt(26);
    for (char c : s) cnt[c - 'a']++;
    int res = 0;
    vector<int> len_cnt(10001);
    for (int i = 0; i < 26; ++i) {
      len_cnt[cnt[i]]++;
    }
    for (int i = 10000; i >= 1; --i) {
      if (len_cnt[i] > 1) {
        res += len_cnt[i] - 1;
        len_cnt[i - 1] += len_cnt[i] - 1;
      }
    }
    return res;
  }
};
