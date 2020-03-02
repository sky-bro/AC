#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int characterReplacement(string s, int k) {
    int n = s.length();
    if (n <= k) return n;
    int max_cnt = 1;
    char max_char = s[0];
    int i = 1;
    int m[26]{};
    ++m[max_char - 'A'];
    for (; i < k; ++i) {
      ++m[s[i] - 'A'];
      if (m[s[i] - 'A'] > max_cnt) {
        max_cnt = m[s[i] - 'A'];
        max_char = s[i];
      }
    }

    int res = max(k, 1);
    int change = res - max_cnt;
    for (int l = 0; i < n; ++i) {
      ++m[s[i] - 'A'];
      if (m[s[i] - 'A'] > max_cnt) {
        ++max_cnt;
        max_char = s[i];
      } else {
        ++change;
        while (change > k) {
          --m[s[l] - 'A'];
          if (s[l++] != max_char) {
            --change;
          } else {
            --max_cnt;
            for (char c = 'A'; c <= 'Z'; ++c) {
              if (m[c - 'A'] > max_cnt) {
                max_char = c;
                max_cnt = m[c - 'A'];
                --change;
                break;
              }
            }
          }
        }
      }
      res = max(res, i - l + 1);
    }
    return res;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  string str = "ABAB";
  int k = 2;
  cout << s.characterReplacement(str, k) << endl;

  str = "ABAA";
  k = 0;
  cout << s.characterReplacement(str, k) << endl;

  str = "AAABBB";
  k = 2;
  cout << s.characterReplacement(str, k) << endl;

  str = "AABABBA";
  k = 1;
  cout << s.characterReplacement(str, k) << endl;
  return 0;
}
