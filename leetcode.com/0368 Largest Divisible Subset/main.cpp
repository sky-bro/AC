#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    sort(nums.rbegin(), nums.rend());
    vector<int> res;
    int n = nums.size();
    if (n == 0) return res;

    vector<int> next(n, -1);
    vector<int> len(n, 1);
    int longest_start = 0, max_len = 1;

    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (len[i] < len[j] + 1 && nums[j] % nums[i] == 0) {
          len[i] = len[j] + 1;
          next[i] = j;
        }
      }
      if (len[i] > max_len) {
        longest_start = i;
        max_len = len[i];
      }
    }
    while (longest_start != -1) {
      res.push_back(nums[longest_start]);
      longest_start = next[longest_start];
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> nums = {1, 2, 3};
  nums = {1, 2, 3, 8, 8, 6, 4, 10};
  s.largestDivisibleSubset(nums);
  return 0;
}
