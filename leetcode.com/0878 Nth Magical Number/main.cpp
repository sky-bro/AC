#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

typedef long long ll;

class Solution {
 public:
  int nthMagicalNumber(int N, int A, int B) {
    ll l = 2, r = 1ll * min(A, B) * N;
    int lcmAB = lcm(A, B); // c++ 17
    while (l < r) {
      ll m = (l + r) / 2;
      ll cnt = m / A - m / lcmAB + m / B;
      if (cnt < N) {
        l = m + 1;
      } else if (cnt > N) {
        r = m - 1;
      } else {
        r = m;
      }
    }
    return l % MOD;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  int N = 1e9, A = 40000, B = 39999;
  cout << s.nthMagicalNumber(N, A, B) << endl;
  return 0;
}

// g++ -std=c++17 -g -o main main.cpp
