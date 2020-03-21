#include <iostream>
#include <vector>

using namespace std;

class Solution {
 private:
  int len_a;
  string a;
  bool is_subsequence(const string& b, int len_b) {
    if (len_b > len_a) return false;
    if (len_b == len_a) return a == b;
    int i = 0, j = 0;
    while (i <= len_a - (len_b - j) && j < len_b) {
      if (a[i++] == b[j]) ++j;
    }
    return j == len_b;
  }

 public:
  string findLongestWord(string s, vector<string>& d) {
    a = s;
    len_a = s.length();
    string res = "";
    int max_len = 0;
    for (const string& b : d) {
      int len_b = b.length();
      if (len_b < max_len) continue;
      if (is_subsequence(b, len_b)) {
        if (max_len == len_b) {
          if (b < res) res = b;
        } else {
          max_len = len_b;
          res = b;
        }
      }
    }
    return res;
  }
};