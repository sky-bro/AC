#include <iostream>
#include <queue>
#include <vector>

#include "leetcode.hpp"

using namespace std;

class Solution {
 public:
  bool isPossible(vector<int>& nums) {
    // {cur_num, -len}
    priority_queue<pair<int, int>> pq;
    for (int i = nums.size() - 1; i >= 0; --i) {
      while (!pq.empty() && pq.top().first > nums[i] + 1) {
        if (pq.top().second <= -3)
          pq.pop();
        else
          return false;
      }
      if (pq.empty() || pq.top().first == nums[i]) {
        pq.emplace(nums[i], -1);
      } else {
        auto p = pq.top();
        pq.pop();
        --p.second;
        p.first = nums[i];
        pq.push(p);
      }
    }
    while (!pq.empty()) {
      if (pq.top().second > -3) return false;
      pq.pop();
    }
    return true;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  string line;
  while (getline(cin, line)) {
    vector<int> nums = stringToIntegerVector(line);

    bool ret = Solution().isPossible(nums);

    string out = boolToString(ret);
    cout << out << endl;
  }
  return 0;
}
