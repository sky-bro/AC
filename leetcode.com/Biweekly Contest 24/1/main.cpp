#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minStartValue(vector<int>& nums) {
    int res = INT32_MAX;
    int sum = -1;
    for (int num : nums) {
      sum += num;
      res = min(res, sum);
    }
    return -res;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> nums = {-3, 2, -3, 4, 2};
  cout << s.minStartValue(nums) << endl;
  return 0;
}
