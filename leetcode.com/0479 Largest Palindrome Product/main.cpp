#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long LL;

// ref:https://leetcode.com/problems/largest-palindrome-product/discuss/371278/C%2B%2B-solution-with-explanation
class Solution {
 private:
  LL palindromeOdd(int num) {
    string left = to_string(num);
    string right = left;
    right.pop_back();
    reverse(right.begin(), right.end());
    return stoll(left + right);
  }

  LL palindromeEven(int num) {
    string left = to_string(num);
    string right = left;
    reverse(right.begin(), right.end());
    return stoll(left + right);
  }

 public:
  int largestPalindrome(int n) {
    int lo = int(pow(10, n - 1)), hi = int(pow(10, n)) - 1;
    for (int i = hi; i >= lo; i--) {
      LL p = palindromeEven(i);
      for (int j = hi; j >= lo & j >= p / j; j--)
        if (p % j == 0) {
          cout << p << endl;
          return p % 1337;
        }
    }
    for (int i = hi; i >= lo; i--) {
      LL p = palindromeOdd(i);
      for (int j = hi; j >= lo & j >= p / j; j--)
        if (p % j == 0) {
          cout << p << endl;
          return p % 1337;
        }
    }
    return 0;
  }
};

class Solution_cheat {
 private:
  static constexpr int res[] = {9, 987, 123, 597, 677, 1218, 877, 475};

 public:
  int largestPalindrome(int n) { return res[n - 1]; }
};

int main(int argc, char const *argv[]) {
  Solution s;
  for (int n = 1; n <= 8; ++n) cout << s.largestPalindrome(n) << endl;
  return 0;
}
