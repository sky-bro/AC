#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    int s = 0;
    m[0]++;
    int res = 0;
    for (int n : nums) {
      s += n;
      auto it = m.find(s - k);
      if (it != m.end()) {
        res += it->second;
      }
      m[s]++;
    }
    return res;
  }
};