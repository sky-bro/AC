#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxSatisfaction(vector<int>& satisfaction) {
    int n = satisfaction.size();
    sort(satisfaction.rbegin(), satisfaction.rend());
    if (satisfaction[0] <= 0) return 0;
    // int i = 0;
    // for (; i < n && satisfaction[i] >= 0; ++i);
    for (int i = 1; i < n; ++i) {
      satisfaction[i] += satisfaction[i - 1];
    }

    int res = 0;
    for (int i = 0; i < n && satisfaction[i] > 0; ++i) {
      res += satisfaction[i];
    }
    return res;
  }
};