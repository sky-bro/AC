#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// the last solution use this idea:
// ref:
// https://leetcode.com/problems/sum-of-square-numbers/discuss/104935/Fermat
// wiki: Fermat's theorem on sums of two squares
// https://en.wikipedia.org/wiki/Fermat's_theorem_on_sums_of_two_squares

// Basic (my initial idea)
class Solution {
 public:
  bool judgeSquareSum(int c) {
    for (int i = 0; i * i <= c / 2; ++i) {
      int aa = i * i, bb = c - aa, b = sqrt(bb);
      if (bb == b * b) return true;
    }
    return false;
  }
};

// Two pointers
class Solution {
public:
    bool judgeSquareSum(int c) {
        long left = 0, right = sqrt(c);
        long sum;
        while(left <= right) {
            sum = right * right + left * left;
            if(sum == c) return true;
            else if(sum > c) right--;
            else left++;
        }
        return false;
    }
};

// Fermat's theorem on sums of two squares
// (SLOW) but math is worth learning
class Solution {
 public:
  bool judgeSquareSum(int c) {
    // if c is already a square number, return true (c = r*r + 0*0)
    int r = int(sqrt(c));
    if (r * r == c) return true;
    // first, seive all possible prime factors of c (that is less than or equal to sqrt(c))
    // at most one factor will be greater than sqrt(c)
    vector<bool> seive(r + 1, true);
    for (int i = 2; i * i <= r; ++i) {
      if (seive[i]) {
        for (int j = i * i; j <= r; j += i) {
          seive[j] = false;
        }
      }
    }
    vector<int> primes;
    for (int i = 2; i <= r; ++i) {
      if (seive[i]) primes.push_back(i);
    }

    // prime factorization here
    int n = primes.size();
    for (int i = 0; i < n && primes[i] < c; ++i) {
      if (primes[i] % 4 == 3) { // this factor must have even power (cnt & 1 == 0)
        int cnt = 0;
        while (c % primes[i] == 0) {
          ++cnt;
          c /= primes[i];
        }
        if (cnt & 1) return false;
      } else
        while (c % primes[i] == 0) c /= primes[i];
    }
    // c == 1 if no factor is greater than original sqrt(c)
    // else c is the only factor that is greater than original sqrt(c)
    if (c % 4 == 3) return false;
    return true;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  int c;
  while (cin >> c) {
    cout << s.judgeSquareSum(c) << endl;
  }
  return 0;
}
