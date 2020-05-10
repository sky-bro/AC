#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countTriplets(vector<int>& arr) {
      int n = arr.size();
      int cnt = 0;
      vector<int> dp(n);
      dp[0] = arr[0];
      for (int i = 1; i < n; ++i) dp[i] = dp[i-1] ^ arr[i];
      for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
          for (int k = j; k < n; ++k) {
            int a = i == 0 ? dp[j-1] : (dp[j-1] ^ dp[i-1]);
            int b = dp[k] ^ dp[j-1];
            if (a == b) ++cnt;
          }
        }
      }
      return cnt;
    }
};
