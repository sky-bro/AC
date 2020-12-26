#include <bits/stdc++.h>

using namespace std;

static int x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}();
typedef long long ll;

class Solution {
 private:
  int n;

 public:
  string maximumBinaryString(string binary) {
    n = binary.size();
    vector<int> nums;
    for (int i = 0; i < n; ++i) {
      nums.push_back(binary[i] - '0');
    }
    for (int i = 0, j = 0; i < n - 1; ++i) {
      if (nums[i] == 1) continue;
      if (nums[i + 1] == 0) {
        nums[i] = 1;
        continue;
      }
      j = max(j, i + 1);
      while (j < n && nums[j]) ++j;
      if (j == n) break;
      nums[j++] = 1;
      nums[i + 1] = 0;
      nums[i] = 1;
    }
    string res = "";
    for (int i = 0; i < n; ++i) {
      res.push_back(nums[i] + '0');
    }
    return res;
  }
};
