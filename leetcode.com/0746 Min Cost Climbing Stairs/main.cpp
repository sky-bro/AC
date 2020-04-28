#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
      int n = cost.size();
      int a = cost[0], b = cost[1];
      for (int i = 2; i < n; ++i) {
        int b_bak = b;
        b = cost[i] + min(a,b);
        a = b_bak;
      }
      return min(a, b);
    }
};
