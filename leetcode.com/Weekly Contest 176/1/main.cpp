#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int countNegatives(vector<vector<int>>& grid) {
    int cnt = 0;
    for (auto& vi : grid) {
      for (int i : vi) {
        if (i < 0) ++cnt;
      }
    }
    return cnt;
  }
};