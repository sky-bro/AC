#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 private:
  unordered_map<int, int> mp;
  int n;
  int dfs(vector<int>& nums, int target) {
    if (target == 0) return 1;
    auto it = mp.find(target);
    if (it != mp.end()) {
      return it->second;
    }
    int res = 0;
    for (int i = 0; i < n && nums[i] <= target; ++i) {
      res += dfs(nums, target - nums[i]);
    }
    return mp[target] = res;
  }

 public:
  int combinationSum4(vector<int>& nums, int target) {
    n = nums.size();
    sort(nums.begin(), nums.end());
    return dfs(nums, target);
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> nums = {1, 2, 3};
  int target = 32;
  cout << s.combinationSum4(nums, target) << endl;
  return 0;
}
