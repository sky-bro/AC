#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int findPoisonedDuration(vector<int>& timeSeries, int duration) {
    int res = 0, n = timeSeries.size(), preEnd = 0;
    for (int i = 0; i < n; ++i) {
      if (timeSeries[i] >= preEnd) {
        res += duration;
      } else {
        res += duration - (preEnd - timeSeries[i]);
      }
      preEnd = timeSeries[i] + duration;
    }
    return res;
  }
};