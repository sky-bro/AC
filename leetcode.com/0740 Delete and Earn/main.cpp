#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
      vector<int> m(10001);
      vector<int> dp(10001);
      for (int num: nums) ++m[num];
      dp[1] = m[1];
      for (int i = 2; i <= 10000; ++i) {
        dp[i] = max(m[i]*i+dp[i-2], dp[i-1]);
      }
      return dp[10000];
    }
};
