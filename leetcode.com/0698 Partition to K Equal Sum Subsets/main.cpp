#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
 private:
  int target, n;
  bool dfs(vector<int> &nums, int i, vector<int> &sums, int k) {
    if (i == n) return true;
    for (int j = 0; j < k; ++j) {
      if (sums[j] + nums[i] > target) continue;
      sums[j] += nums[i];
      if (dfs(nums, i + 1, sums, k)) return true;
      sums[j] -= nums[i];
    }
    return false;
  }

 public:
  bool canPartitionKSubsets(vector<int> &nums, int k) {
    int total_sum = accumulate(nums.begin(), nums.end(), 0);
    if (total_sum % k) return false;
    target = total_sum / k;
    sort(nums.rbegin(), nums.rend());
    if (nums[0] > target) return false;
    n = nums.size();
    vector<int> sums(k);
    if (dfs(nums, 0, sums, k)) return true;
    return false;
  }
};

int main(int argc, char const *argv[]) {
  vector<int> nums = {960,  3787, 1951, 5450, 4813, 752,  1397, 801,
                      1990, 1095, 3643, 8133, 893,  5306, 8341, 5246};
  int k;
  nums = {4,3,2,3,5,2,1};
  k = 4;
  Solution s;
  cout << s.canPartitionKSubsets(nums, k) << endl;
  return 0;
}
