#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

inline bool cmp(const vector<int>& a, const vector<int>& b) {
  return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
}

class Solution {
 public:
  vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    sort(people.begin(), people.end(), cmp);
    int n = people.size();
    vector<vector<int>> res(n, vector<int>(2, -1));
    for (int i = 0; i < n;) {
      int cur_height = people[i][0];
      for (int j = 0, cnt = 0; i < n && cur_height == people[i][0]; ++j) {
        if (res[j][1] == -1) {  // no people's height = 0... wrong!
          if (people[i][1] == cnt++) {
            res[j][0] = people[i][0];
            res[j][1] = people[i][1];
            ++i;
          }
        }
      }
    }
    return res;
  }
};