#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> cnt(26);
        int total = 0;
        for (char c: licensePlate) {
          if (c <= 'Z' && c >= 'A') {
            ++cnt[c-'A'];
            ++total;
          } else if (c <= 'z' && c >= 'a') {
            ++cnt[c-'a'];
            ++total;
          }
        }
        string res;
        bool valid = false;
        int N = 0;
        for (const string &word: words) {
          int n = word.length();
          if (N && N <= n) continue;
          vector<int> cur_cnt = cnt;
          int cur_total = total;
          for (char c: word) {
            if (cur_cnt[c-'a']) {
              --cur_cnt[c-'a'];
              if (--cur_total == 0) break;
            }
          }
          if (cur_total == 0) {
            N = n;
            res = word;
          }
        }
        return res;
    }
};
