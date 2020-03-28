#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    int len1 = s1.length(), len2 = s2.length();
    if (len1 > len2) return false;
    int cnt[26]{};
    int zero = len1;
    for (char c : s1) cnt[c - 'a']--;
    int i = 0;
    for (; i < len1; ++i) {
      ++cnt[s2[i] - 'a'] <= 0 ? --zero : ++zero;
    }
    if (zero == 0) return true;
    for (; i < len2; ++i) {
      ++cnt[s2[i] - 'a'] <= 0 ? --zero : ++zero;
      --cnt[s2[i - len1] - 'a'] >= 0 ? --zero : ++zero;
      if (zero == 0) return true;
    }
    return false;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  string s1, s2;
  while (cin >> s1 >> s2) {
    cout << s.checkInclusion(s1, s2) << endl;
  }
  return 0;
}
