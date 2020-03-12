#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int findSubstringInWraproundString(string p) {
    int cnt[26]{};
    int n = p.length();
    for (int i = 0; i < n;) {
      int len = 1;
      for (; i + len < n && p[i + len] == (p[i + len - 1] - 'a' + 1) % 26 + 'a';
           ++len)
        ;
      for (int j = 0; j < len; ++j) {
        if (cnt[p[i + j] - 'a'] >= len - j) break;
        cnt[p[i + j] - 'a'] = len - j;
      }
      i += len;
    }
    int res = 0;
    for (int i = 0; i < 26; ++i) res += cnt[i];
    return res;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  string p;
  while (cin >> p) {
    cout << s.findSubstringInWraproundString(p) << endl;
  }
  return 0;
}
