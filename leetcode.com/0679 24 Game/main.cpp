#include <iostream>
#include <vector>

using namespace std;

const double EPS = 1e-3;

class Solution {
 private:
  bool is24(double a) { return abs(a - 24) < EPS; }
  bool dfs(vector<double>& nums, int n) {
    if (n == 1) return is24(nums[0]);
    for (int i = 0; i < n - 1; ++i) {
      swap(nums[i], nums[n - 1]);
      for (int j = i; j < n - 1; ++j) {
        double bak = nums[j];
        // +
        nums[j] = bak + nums[n - 1];
        if (dfs(nums, n - 1)) return true;
        nums[j] = bak;
        // -
        nums[j] = bak - nums[n - 1];
        if (dfs(nums, n - 1)) return true;
        nums[j] = nums[n - 1] - bak;
        if (dfs(nums, n - 1)) return true;
        nums[j] = bak;
        // *
        nums[j] = bak * nums[n - 1];
        if (dfs(nums, n - 1)) return true;
        nums[j] = bak;
        // / (can't divide by 0)
        if (nums[n - 1]) {
          nums[j] = bak / nums[n - 1];
          if (dfs(nums, n - 1)) return true;
          nums[j] = bak;
        }
        if (bak) {
          nums[j] = nums[n - 1] / bak;
          if (dfs(nums, n - 1)) return true;
          nums[j] = bak;
        }
      }
      swap(nums[i], nums[n - 1]);
    }
    return false;
  }

 public:
  bool judgePoint24(vector<int>& nums) {
    vector<double> _nums(nums.begin(), nums.end());
    return dfs(_nums, 4);
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> nums = {4, 1, 8, 7};  // true
  nums = {1, 3, 4, 6};              // true
  cout << s.judgePoint24(nums) << endl;
  return 0;
}
