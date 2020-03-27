#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  string optimalDivision(vector<int>& nums) {
    string res = to_string(nums[0]);
    int n = nums.size();
    if (n == 1)
      return res;
    else {
      res.push_back('/');
      if (n == 2) {
        res.append(to_string(nums[1]));
      } else {
        res.push_back('(');
        res.append(to_string(nums[1]));
        for (int i = 2; i < n; ++i) {
          res.push_back('/');
          res.append(to_string(nums[i]));
        }
        res.push_back(')');
      }
      return res;
    }
  }
};