#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int sumOddLengthSubarrays(vector<int>& arr) {
    int n = arr.size();
    int res = 0;
    for (int i = 0; i < n; ++i) {
      int cur = arr[i];
      res += cur;
      for (int j = i + 2; j < n; j += 2) {
        cur += arr[j] + arr[j - 1];
        res += cur;
      }
    }
    return res;
  }
};