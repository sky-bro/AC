#include <iostream>
#include <vector>

using namespace std;

// idea and discussion can be found here:
// https://leetcode.com/problems/2-keys-keyboard/discuss/105897/Loop-best-case-log(n)-no-DP-no-extra-space-no-recursion-with-explanation

// awesome, tricky
// 1 -> 6
// 1 -> 3 -> 6 (5 steps)
// 1 -> 2 -> 6 (5 steps), it's the same!!

// original post
class Solution {
 public:
  int minSteps(int n) {
    int s = 0;
    for (int d = 2; d <= n; d++) {
      while (n % d == 0) {
        s += d;
        n /= d;
      }
    }
    return s;
  }
};

// best solution
// from:
// https://leetcode.com/problems/2-keys-keyboard/discuss/105897/Loop-best-case-log(n)-no-DP-no-extra-space-no-recursion-with-explanation/108355
/*
// ruby:
require 'prime'

def min_steps(n)
  n.prime_division.map { |p, e| p * e }.sum
end
*/

// essentially a prime factorization problem

int main(int argc, char const *argv[]) {
  Solution s;
  int n;
  while (cin >> n) {
    cout << s.minSteps(n) << endl;
  }
  return 0;
}
