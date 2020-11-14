#include <cstring>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int dp[51][1024];
int sums[1024];

class Solution {
 public:
  int m, n, mask;
  bool canDistribute(vector<int>& nums, vector<int>& quantity) {
    map<int, int> mp;
    for (int num : nums) {
      mp[num]++;
    }
    m = quantity.size();
    n = mp.size();
    mask = 1 << m;
    vector<int> arr(n);
    int i = 0;
    for (auto it = mp.rbegin(); it != mp.rend(); ++i, ++it) {
      arr[i] = it->second;
    }
    for (i = 0; i < mask; ++i) {
      int sum = 0;
      for (int k = 0; k != m; ++k) {
        if (i & (1 << k)) {
          sum += quantity[k];
        }
      }
      sums[i] = sum;
    }
    memset(dp, 0, sizeof(dp));
    dp[n][mask - 1] = true;
    for (int i = n - 1; i >= 0; --i) {
      for (int j = 0; j < mask; ++j) {
        for (int k = 0; k < mask; ++k) {
          if ((j & k) == 0 && sums[k] <= arr[i] && dp[i + 1][j | k]) {
            dp[i][j] = true;
            break;
          }
        }
      }
    }
    return dp[0][0];
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> nums = {1, 2, 3, 3};
  vector<int> quan = {2};
  nums = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23,
          24, 25, 26, 27, 28, 29, 30, 30, 31, 31, 32, 32, 33, 33,
          34, 34, 35, 35, 36, 36, 37, 37, 38, 38, 39, 39};
  quan = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
  cout << s.canDistribute(nums, quan) << endl;
  return 0;
}
