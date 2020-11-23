#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int minOperations(vector<int>& nums, int x) {
    int res = INT32_MAX;
    int n = nums.size();
    int sum = 0;
    int i = 0;
    for (; i < n; ++i) {
      sum += nums[i];
      if (sum > x) break;
    }
    if (sum < x)
      return -1;
    else if (sum == x)
      return n;

    for (int j = n; i >= 0; --i) {
      sum -= nums[i];
      if (sum == x) res = min(res, i + (n - j));
      if (sum < x)
        for (--j;; --j) {
          sum += nums[j];
          if (sum == x) {
            res = min(res, i + (n - j));
          } else if (sum > x)
            break;
        }
    }

    return res == INT32_MAX ? -1 : res;
  }
};

int main(int argc, char const* argv[]) {
  vector<int> nums = {1, 1, 4, 3, 2};
  int x = 5;
  Solution s;
  cout << s.minOperations(nums, x) << endl;
  return 0;
}
