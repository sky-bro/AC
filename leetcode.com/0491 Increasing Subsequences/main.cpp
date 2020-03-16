#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
 private:
  vector<vector<int>> res;
  set<vector<int>> visited;
  int n;
  void dfs(vector<int>& nums, int idx, int cur_max, vector<int>& path) {
    if (idx == n) {
      if (path.size() > 1) {
        if (visited.find(path) == visited.end()) {
          visited.emplace(path);
          res.push_back(path);
        }
      }
      return;
    }
    if (nums[idx] >= cur_max) {
      path.push_back(nums[idx]);
      dfs(nums, idx + 1, nums[idx], path);
      path.pop_back();
    }
    dfs(nums, idx + 1, cur_max, path);
  }

 public:
  vector<vector<int>> findSubsequences(vector<int>& nums) {
    res.clear();
    n = nums.size();
    if (n == 0) return res;

    vector<int> path;
    dfs(nums, 0, INT32_MIN, path);
    return res;
  }
};