#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

class Solution {
 private:
  vector<int> A;
  unordered_map<int, int> dp;
  int n;
  long long f(int pnum) {
    if (dp.find(pnum) != dp.end()) return dp[pnum];
    long long res = 1;
    for (int i = 0; pnum/A[i] >= A[i]; ++i) {
      int other = pnum / A[i];
      if (other * A[i] == pnum && binary_search(A.begin(), A.end(), other)) {
        long long lnum = f(A[i]);
        if (other == A[i]) {
          res = (res + lnum*lnum % MOD) % MOD;
        } else {
          res = (res + 2 * lnum * f(other) % MOD) % MOD;
        }
      }
    }
    return dp[pnum] = res;
  }

 public:
  int numFactoredBinaryTrees(vector<int>& A) {
    this->n = A.size();
    this->A = A;
    sort(this->A.begin(), this->A.end());
    this->dp.clear();
    long long res = 0;
    for (int a : A) {
      res = (res + f(a)) % MOD;
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> A = {2, 4};
  A = {2, 4, 5, 10};
  cout << s.numFactoredBinaryTrees(A) << endl;
  return 0;
}
