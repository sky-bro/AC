#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> frequencySort(vector<int>& nums) {
    int n = nums.size();
    vector<set<int>> d(n + 1);
    map<int, int> mp;
    for (int num : nums) {
      if (mp.find(num) == mp.end())
        mp[num] = 1;
      else
        mp[num]++;
    }
    for (auto p : mp) {
      d[p.second].insert(p.first);
    }
    vector<int> res;
    for (int i = 1; i <= n; ++i) {
      auto& st = d[i];
      for (auto it = st.rbegin(); it != st.rend(); ++it) {
        for (int j = 0; j < i; ++j) res.push_back(*it);
      }
    }
    return res;
  }
};
