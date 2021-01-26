#include <iostream>
#include <vector>

using namespace std;

// ref: C++ 5 lines, search in decreasing stack O(n log n)
// https://leetcode.com/problems/maximum-width-ramp/discuss/208331/C%2B%2B-5-lines-search-in-decreasing-stack-O(n-log-n)
class Solution {
 public:
  int maxWidthRamp(vector<int>& A) {
    int res = 0, n = A.size();
    vector<int> v = {0};
    for (int i = 1; A[v.back()] > A.back(); ++i) {
      if (A[v.back()] > A[i]) v.push_back(i);
    }
    for (int i = n - 1; i > res; --i) {
      while (!v.empty() && A[v.back()] <= A[i]) {
        res = max(res, i - v.back());
        v.pop_back();
      }
      if (v.empty()) break;
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> A = {9, 8, 1, 0, 1, 9, 4, 0, 4, 1};
  cout << s.maxWidthRamp(A) << endl;
  return 0;
}
