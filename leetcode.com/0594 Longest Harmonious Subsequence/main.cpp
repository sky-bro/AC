#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int findLHS(vector<int> &nums) {
    unordered_map<int, int> mp;
    for (int num : nums) mp[num]++;
    int res = 0;
    for (auto &p : mp) {
      auto it = mp.find(p.first + 1);
      if (it == mp.end()) continue;
      res = max(res, it->second + p.second);
    }
    return res;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  vector<int> nums = {1, 3, 2, 2, 5, 2, 3, 7};
  cout << s.findLHS(nums) << endl;
  return 0;
}
