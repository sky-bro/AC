#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
    unordered_map<string, int> mp;
    int n1 = list1.size(), n2 = list2.size();
    for (int i = 0; i < n1; ++i) mp[list1[i]] = i;
    vector<string> res;
    int min_sum = n1 + n2;
    for (int i = 0; i < n2; ++i) {
      auto it = mp.find(list2[i]);
      if (it == mp.end() || it->second + i > min_sum) continue;
      int tmp_sum = it->second + i;
      if (tmp_sum < min_sum) {
        res.clear();
        min_sum = tmp_sum;
      }
      res.push_back(list2[i]);
    }
    return res;
  }
};