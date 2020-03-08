#include <cctype>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 private:
  static constexpr char* vowels = "aeiou";

 public:
  int findTheLongestSubstring(string s) {
    vector<int> dp(32, -2);
    dp[0] = -1;
    int res = 0, n = s.length();
    int cur = 0;
    for (int i = 0; i < n; ++i) {
      char* p = strchr(vowels, s[i]);
      if (p) cur ^= (1 << (p - vowels));
      if (dp[cur] == -2)
        dp[cur] = i;
      else
        res = max(res, i - dp[cur]);
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  string str;
  while (cin >> str) {
    cout << s.findTheLongestSubstring(str) << endl;
  }
  return 0;
}
