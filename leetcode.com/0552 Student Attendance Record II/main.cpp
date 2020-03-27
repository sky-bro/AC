#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

typedef unsigned long long ull;

class Solution {
 private:
  static const ull MOD = (ull)(1e9) + 7;

 public:
  int checkRecord(int n) {
    ull D[2][7] = {{1, 0, 1, 0, 0, 0, 1}};
#define P(i) D[i][0]
#define PA(i) D[i][1]
#define L(i) D[i][2]
#define LA(i) D[i][3]
#define LL(i) D[i][4]
#define LLA(i) D[i][5]
#define A(i) D[i][6]

    for (int i = 1; i < n; ++i) {
      bool j = i & 1;
      P(j) = (P(!j) + L(!j) + LL(!j)) % MOD;
      PA(j) = (PA(!j) + LA(!j) + LLA(!j) + A(!j)) % MOD;
      L(j) = P(!j);
      LA(j) = (PA(!j) + A(!j)) % MOD;
      LL(j) = L(!j);
      LLA(j) = LA(!j);
      A(j) = (P(!j) + L(!j) + LL(!j)) % MOD;
    }
    return accumulate(&D[~n & 1][0], &D[~n & 1][7], 0ULL) % MOD;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  int n;
  while (cin >> n) {
    cout << s.checkRecord(n) << endl;
  }
  return 0;
}
