#include <iostream>
#include <vector>

using namespace std;

// ref: All Even Length Palindrome are Divisible by 11
// https://leetcode.com/problems/prime-palindrome/discuss/146798/JavaC%2B%2BPython-All-Even-Length-Palindrome-are-Divisible-by-11

class Solution {
 private:
  bool isPrime(int x) {
    if (x < 2 || x % 2 == 0) return x == 2;
    for (int i = 3; i * i <= x; i += 2) {
      if (x % i == 0) return false;
    }
    return true;
  }

 public:
  int primePalindrome(int N) {
    if (N >= 8 && N <= 11) return 11;
    for (int i = 1; i < 100000; ++i) {
      string s = to_string(i), r = string(s.rbegin(), s.rend());
      int x = stoi(s + r.substr(1));
      if (x >= N && isPrime(x)) return x;
    }
    return -1;
  }
};
