#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
 public:
  int numSubarraysWithSum(vector<int>& A, int S) {
    partial_sum(A.begin(), A.end(), A.begin());
    int res = 0;
    // just binary search
    for (int i = A.size() - 1; i >= 0; --i) {
      if (A[i] - S == 0) ++res;
      auto it = lower_bound(A.begin(), A.begin() + i, A[i] - S);
      auto it2 = lower_bound(A.begin(), A.begin() + i, A[i] - S + 1);
      res += it2 - it;
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> A = {0, 0, 0, 0, 0};
  int S = 0;
  cout << s.numSubarraysWithSum(A, S) << endl;
  return 0;
}
