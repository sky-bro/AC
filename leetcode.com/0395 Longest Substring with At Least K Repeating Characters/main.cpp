#include <iostream>
#include <vector>

using namespace std;

// ref: Java Strict O(N) Two-Pointer Solution
// https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/discuss/87739/Java-Strict-O(N)-Two-Pointer-Solution

// ref: 4 lines Python -- StefanPochmann
// https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/discuss/87768/4-lines-Python

class Solution {
 public:
  int longestSubstring(string s, int k) {
    int res = 0;
    int n = s.length();
    for (int unique_cnt = 1; unique_cnt <= 26; ++unique_cnt) {
      int count[26]{};
      int left = 0, right = 0, cur_unique_cnt = 0, no_less_than_k = 0;
      while (right < n && n - res > left) {
        if (cur_unique_cnt <= unique_cnt) {
          int idx = s[right++] - 'a';
          if (count[idx]++ == 0) cur_unique_cnt++;
          if (count[idx] == k) no_less_than_k++;
        } else {
          int idx = s[left++] - 'a';
          if (count[idx]-- == k) no_less_than_k--;
          if (count[idx] == 0) cur_unique_cnt--;
        }

        if (no_less_than_k == unique_cnt && cur_unique_cnt == unique_cnt) {
          res = max(res, right - left);
        }
      }
    }
    return res;
  }
};