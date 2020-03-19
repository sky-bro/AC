#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> findRelativeRanks(vector<int>& nums) {
    int n = nums.size();
    vector<int> rank(n);
    for (int i = 0; i < n; ++i) rank[i] = i;
    sort(rank.begin(), rank.end(),
         [&](int a, int b) { return nums[a] > nums[b]; });
    vector<string> res(n);
    for (int i = 3; i < n; ++i) res[rank[i]] = to_string(i + 1);
    if (1 <= n) res[rank[0]] = "Gold Medal";
    if (2 <= n) res[rank[1]] = "Silver Medal";
    if (3 <= n) res[rank[2]] = "Bronze Medal";
    return res;
  }
};