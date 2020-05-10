#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
      int n = arr.size();
      int res = 1;
      vector<int> max_dp(n), min_dp(n);
      max_dp[0] = arr[0], min_dp[n-1] = arr[n-1];
      for (int i = 1; i < n; ++i) {
        max_dp[i] = max(max_dp[i-1], arr[i]);
        min_dp[n-i-1] = min(min_dp[n-i], arr[n-i-1]);
      }
      for (int i = 0; i < n-1; ++i) {
        if (max_dp[i] <= min_dp[i+1]) ++res;
      }
      return res;
    }
};

