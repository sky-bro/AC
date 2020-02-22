#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int numberOfSubstrings(string s) {
    int n = s.length();
    int cnt[3]{0};
    cnt[s[0] - 'a']++;

    int prev_start = -1;
    int left = 0;  //, right = 0;
    int res = 0;
    for (int i = 1; i < n; ++i) {
      if (s[left] == s[i]) {  // keep cnt[s[left]-'a'] = 1
        ++left;
        // ++right;
        while (cnt[s[left] - 'a'] > 1) {
          cnt[s[left++] - 'a']--;
        }
      } else {
        cnt[s[i] - 'a']++;
        if (cnt[0] && cnt[1] && cnt[2]) {
          res += (left - prev_start) * (n - i);
          prev_start = left;
          cnt[s[left++] - 'a']--;
          while (cnt[s[left] - 'a'] > 1) {
            cnt[s[left++] - 'a']--;
          }
        }
      }
    }
    return res;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  string str;
  while (cin >> str) {
    cout << s.numberOfSubstrings(str) << endl;
  }

  return 0;
}
