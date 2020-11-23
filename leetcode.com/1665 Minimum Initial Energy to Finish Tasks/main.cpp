#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int minimumEffort(vector<vector<int>>& tasks) {
    int res = 0;
    for (auto& t : tasks) res += t[0];
    sort(tasks.begin(), tasks.end(), [](vector<int>& a, vector<int>& b) {
      return a[1] - a[0] > b[1] - b[0];
    });
    int remain = res;
    for (auto& t : tasks) {
      if (remain < t[1]) {
        res += t[1] - remain;
        remain = t[1];
      }
      remain -= t[0];
    }
    return res;
  }
};
