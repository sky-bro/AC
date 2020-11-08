#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int getMaximumGenerated(int n) {
    if (n <= 1) return n;
    vector<int> arr(n + 1);
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i <= n; ++i) {
      arr[i] = (i & 1) ? arr[i / 2] + arr[i / 2 + 1] : arr[i / 2];
    }
    return *max_element(arr.begin(), arr.end());
  }
};
