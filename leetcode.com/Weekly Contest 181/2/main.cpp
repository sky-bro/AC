#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
 private:
  int f(int a) {
    int cnt = 0, res = 0, m = int(sqrt(a));
    if (m * m == a) return 0;
    for (int i = 1; i <= m; ++i) {
      if (a % i == 0) {
        cnt += 2;
        if (cnt > 4) return 0;
        res += i + a / i;
      }
    }
    return cnt == 4 ? res : 0;
  }

 public:
  int sumFourDivisors(vector<int>& nums) {
    int res = 0;
    for (int i = 0; i < nums.size(); ++i) {
      res += f(nums[i]);
    }
    return res;
  }
};