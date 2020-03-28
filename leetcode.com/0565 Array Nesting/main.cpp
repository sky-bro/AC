#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int arrayNesting(vector<int>& nums) {
    int n = nums.size();

    vector<bool> vis(n);
    int max_len = 1;
    for (int i = 0; i < n; ++i) {
      if (vis[i]) continue;

      int slow = i, fast = nums[i];

      bool skip = false;
      while (slow != fast) {
        if (vis[slow]) {
          skip = true;
          break;
        }
        vis[slow] = true;
        slow = nums[slow];
        fast = nums[nums[fast]];
      }
      if (skip) continue;

      slow = i;
      while (slow != fast) {
        slow = nums[slow];
        fast = nums[nums[fast]];
      }
      int cur_len = 1;
      fast = nums[slow];
      while (slow != fast) {
        fast = nums[fast];
        ++cur_len;
      }
      max_len = max(max_len, cur_len);
    }
    return max_len;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> nums = {5, 4, 0, 3, 1, 6, 2};
  cout << s.arrayNesting(nums) << endl;
  return 0;
}
