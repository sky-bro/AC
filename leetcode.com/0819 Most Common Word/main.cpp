#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  string mostCommonWord(string paragraph, vector<string>& banned) {
    unordered_map<string, int> freq;
    unordered_set<string> banned_set(banned.begin(), banned.end());
    string s;
    int i = 0, n = paragraph.size();
    while (i < n) {
      int len = 0;
      while (i + len < n) {
        if (paragraph[i + len] <= 'z' && paragraph[i + len] >= 'a') {
          ++len;
        } else if (paragraph[i + len] <= 'Z' && paragraph[i + len] >= 'A') {
          paragraph[i + len] += 'a' - 'A';
          ++len;
        } else {
          break;
        }
      }
      if (len) {
        s = paragraph.substr(i, len);
        if (banned_set.find(s) == banned_set.end()) freq[s]++;
      }
      ++i;
      i += len;
    }
    int cur_freq = 0;
    for (auto& p : freq) {
      if (p.second > cur_freq) {
        s = p.first;
        cur_freq = p.second;
      }
    }
    return s;
  }
};
