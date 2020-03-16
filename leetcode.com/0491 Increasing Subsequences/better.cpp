#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// ref: C++ dfs solution using unordered_set
// https://leetcode.com/problems/increasing-subsequences/discuss/97124/C%2B%2B-dfs-solution-using-unordered_set
class Solution {
 public:
  vector<vector<int>> findSubsequences(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> seq;
    dfs(res, seq, nums, 0);
    return res;
  }

  void dfs(vector<vector<int>>& res, vector<int>& seq, vector<int>& nums,
           int pos) {
    if (seq.size() > 1) res.push_back(seq);
    unordered_set<int> hash;
    for (int i = pos; i < nums.size(); ++i) {
      if ((seq.empty() || nums[i] >= seq.back()) &&
          hash.find(nums[i]) == hash.end()) {
        seq.push_back(nums[i]);
        dfs(res, seq, nums, i + 1);
        seq.pop_back();
        hash.insert(nums[i]);
      }
    }
  }
};