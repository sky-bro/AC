#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  int numberOfArithmeticSlices(vector<int>& A) {
    int res = 0, n = A.size();
    if (n < 3) return 0;
    vector<unordered_map<long long, int>> dp(n);
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        // [0,2000000000,-294967296] overflow
        long long diff = (long long)(A[i]) - (long long)(A[j]);
        dp[i][diff] += 1;
        auto it = dp[j].find(diff);
        if (it != dp[j].end()) {
          dp[i][diff] += it->second;
          res += it->second;
        }
      }
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> A = {1, 1, 1, 1, 1};
  A = {1, 1, 2, 3};
  A = {2, 2, 3, 3, 4, 5};
  cout << s.numberOfArithmeticSlices(A) << endl;
  return 0;
}
