#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
 public:
  int minMoves(vector<int>& nums) {
    int res = 0;
    int min_num = *min_element(nums.begin(), nums.end());
    for (int num : nums) res += num - min_num;
    return res;
  }
};