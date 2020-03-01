#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>

using namespace std;

// ref:
// https://leetcode.com/problems/strong-password-checker/discuss/91007/C%2B%2B-0ms-O(n)-35-lines-solution-with-detailed-explanation
// ref: Simple Python solution
// https://leetcode.com/problems/strong-password-checker/discuss/91008/Simple-Python-solution

class Solution {
 public:
  int strongPasswordChecker(string s) {
    int n = s.length();
    // It has at least 6 characters and at most 20 characters.
    int missing_type = 3;  // lowercase, uppercase, digit
    missing_type -=
        any_of(s.begin(), s.end(), [](char c) { return islower(c); });
    missing_type -=
        any_of(s.begin(), s.end(), [](char c) { return isupper(c); });
    missing_type -=
        any_of(s.begin(), s.end(), [](char c) { return isdigit(c); });
    int i = 2;
    int one = 0, two = 0;
    int change = 0;
    while (i < n) {
      if (s[i] == s[i - 1] && s[i] == s[i - 2]) {
        int len = 3;
        for (++i; i < n && s[i] == s[i - 1]; ++i, ++len)
          ;
        change += len / 3;
        if (len % 3 == 0)
          ++one;
        else if (len % 3 == 1)
          ++two;
      } else {
        ++i;
      }
    }

    if (n < 6) {
      return max(missing_type, 6 - n);
    } else if (n <= 20) {
      return max(missing_type, change);
    } else {
      int delete_cnt = n - 20;
      change -= min(delete_cnt, one);
      change -= min(max(delete_cnt - one, 0), two * 2) / 2;
      change -= max(delete_cnt - one - 2 * two, 0) / 3;
      return delete_cnt + max(missing_type, change);
    }
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  string str = "adafdasdsdssssjdkkkkkkkkwwwa";
  str = "1111111111";
  cout << s.strongPasswordChecker(str) << endl;
  return 0;
}
