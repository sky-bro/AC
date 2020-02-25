#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxRotateFunction(vector<int>& A) {
    int n = A.size();
    long long sum = 0;
    int cur_res = 0;
    for (int i = 0; i < n; ++i) {
      sum += A[i];
      cur_res += i * A[i];
    }
    int res = cur_res;
    for (int i = n - 1; i > 0; --i) {
      cur_res += sum - n * (long long)A[i];
      res = max(res, cur_res);
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  vector<int> A = {4, 3, 2, 6};  // 26;
  A = {2147483647, 2147483647};
  Solution sol;
  cout << sol.maxRotateFunction(A) << endl;
  return 0;
}
