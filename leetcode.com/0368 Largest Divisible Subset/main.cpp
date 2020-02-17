#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    vector<int> res;
    multiset<int> num_set(nums.begin(), nums.end());
    while (num_set.size() <= res.size()) {
      vector<int> tmp_res;
      auto it = num_set.begin();
      tmp_res.push_back(*it);
      num_set.erase(it++);
      for (; it != num_set.end();) {
        if ((*it) % tmp_res.back() == 0) {
          tmp_res.push_back(*it);
          num_set.erase(it++);
        } else {
          ++it;
        }
      }
      if () }
    return res;
  }
};