#include <algorithm>
#include <iostream>
#include <vector>

#include "leetcode.hpp"

using namespace std;

class Solution {
 public:
  vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int n = arr.size();
    int r = lower_bound(arr.begin(), arr.end(), x) - arr.begin(), l = r - 1,
        remain = k;
    while (remain-- && l >= 0 && r < n) {
      if (x - arr[l] <= arr[r] - x) {
        --l;
      } else {
        ++r;
      }
    }
    if (l < 0)
      return vector<int>(arr.begin(), arr.begin() + k);
    else if (r >= n)
      return vector<int>(arr.begin() + (n - k), arr.end());
    else
      return vector<int>(arr.begin() + (l + 1), arr.begin() + r);
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> arr = {1, 2, 3, 4, 5};
  int k = 3;  // 4 4
  int x = 6;  // -1 3
  printArr(s.findClosestElements(arr, k, x));

  arr = {0, 0, 1, 2, 3, 3, 4, 7, 7, 8};
  k = 3;
  x = 5;
  printArr(s.findClosestElements(arr, k, x));
  return 0;
}
