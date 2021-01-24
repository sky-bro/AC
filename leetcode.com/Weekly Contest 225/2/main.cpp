#include <bits/stdc++.h>

using namespace std;

static int x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}();
typedef long long ll;

class Solution {
 private:
  int n1, n2;

 public:
  int minCharacters(string a, string b) {
    n1 = a.length(), n2 = b.length();
    vector<int> cnt1(26), cnt2(26);
    for (char c : a) ++cnt1[c - 'a'];
    for (char c : b) ++cnt2[c - 'a'];
    // case 3
    int res = n1 - (*max_element(cnt1.begin(), cnt1.end())) + n2 -
              (*max_element(cnt2.begin(), cnt2.end()));
    // case 1, 2
    for (int i = 0; i < 25; ++i) {
      int cur1 = 0, cur2 = 0;
      for (int j = 0; j < 26; ++j) {
        if (j <= i) {
          cur1 += cnt2[j];
          cur2 += cnt1[j];
        } else {
          cur1 += cnt1[j];
          cur2 += cnt2[j];
        }
      }
      res = min(min(cur1, cur2), res);
    }
    return res;
  }
};
