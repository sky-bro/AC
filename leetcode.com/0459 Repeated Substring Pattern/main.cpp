#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool repeatedSubstringPattern(string s) {
    int n = s.length();
    for (int substr_len = 1; substr_len <= n / 2; ++substr_len) {
      if (n % substr_len) continue;
      int start = 0;
      for (int i = 0; start < n - substr_len; start += substr_len, i = start) {
        while (i < start + substr_len && s[i] == s[i + substr_len]) ++i;
        if (i != start + substr_len) break;
      }
      if (start == n - substr_len) return true;
    }
    return false;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  string str;
  while (cin >> str) {
    cout << s.repeatedSubstringPattern(str) << endl;
  }
  return 0;
}
