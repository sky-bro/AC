// ref: Java O(n) Time O(1) Space
// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/discuss/103057/Java-O(n)-Time-O(1)-Space
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int findUnsortedSubarray(vector<int>& A) {
    int n = A.size(), beg = -1, end = -2, _min = A[n - 1], _max = A[0];
    for (int i = 1; i < n; i++) {
      if (A[i] < _max)
        end = i;
      else
        _max = A[i];
      if (A[n - 1 - i] > _min)
        beg = n - 1 - i;
      else
        _min = A[n - 1 - i];
    }
    return end - beg + 1;
  }
};

int main(int argc, char const* argv[]) {
  vector<int> nums = {2, 6, 4, 8, 10, 9, 15};
  nums = {2, 3, 4, 5, 6, 6, 4, 8, 10, 9, 15};  // 7
  nums = {1, 2, 3, 4};                         // 0
  Solution s;
  cout << s.findUnsortedSubarray(nums) << endl;
  return 0;
}
