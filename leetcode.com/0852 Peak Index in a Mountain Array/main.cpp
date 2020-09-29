#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int peakIndexInMountainArray(vector<int>& arr) {
    int l = 1, r = arr.size() - 2;
    while (true) {
      int m = (l + r) / 2;
      if (arr[m] > arr[m - 1]) {
        if (arr[m] > arr[m + 1]) return m;
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
    return -1;
  }
};
