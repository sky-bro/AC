#include <iostream>
#include <vector>

using namespace std;

// ref:[C++/Java/Python] DP O(N) Solution
// https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/discuss/119879/C%2B%2BJavaPython-DP-O(N)-Solution

class Solution {
 public:
  int minSwap(vector<int>& A, vector<int>& B) {
    int n = A.size();
    vector<int> do_not_swap(n),
        do_swap(n);  // op at last index is not swap / swap
    do_swap[0] = 1;
    for (int i = 1; i < n; ++i) {
      // at least one of the two ok's below is true.
      bool ok1 = A[i - 1] < A[i] && B[i - 1] < B[i];  // can swap both
      bool ok2 = A[i - 1] < B[i] && B[i - 1] < A[i];  // can swap one
      do_swap[i] = do_not_swap[i] = n;  // should be smaller than n
      if (ok1) {
        do_not_swap[i] = do_not_swap[i - 1];
        do_swap[i] = do_swap[i - 1] + 1;
      }
      if (ok2) {
        do_not_swap[i] = min(do_not_swap[i], do_swap[i - 1]);
        do_swap[i] = min(do_not_swap[i - 1] + 1, do_swap[i]);
      }
    }
    return min(do_not_swap[n - 1], do_swap[n - 1]);
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  /*
  [0,3,5,8,9]
  [2,1,4,6,9]
  */
  vector<int> A = {0, 3, 5, 8, 9}, B = {2, 1, 4, 6, 9};
  cout << s.minSwap(A, B) << endl;
  return 0;
}
