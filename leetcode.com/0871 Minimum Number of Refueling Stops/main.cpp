#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// ref: DP O(N^2) and Priority Queue O(NlogN)
// https://leetcode.com/problems/minimum-number-of-refueling-stops/discuss/149839/DP-O(N2)-and-Priority-Queue-O(NlogN)

class Solution {
 public:
  int minRefuelStops(int target, int cur, vector<vector<int>> s) {
    int i = 0, res;
    priority_queue<int> pq;
    for (res = 0; cur < target; res++) {
      while (i < s.size() && s[i][0] <= cur) pq.push(s[i++][1]);
      if (pq.empty()) return -1;
      cur += pq.top(), pq.pop();
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  int target = 1000, startFuel = 299;
  vector<vector<int>> stations = {
      {13, 21},   {26, 115},  {100, 47},  {225, 99},  {299, 141},
      {444, 198}, {608, 190}, {636, 157}, {647, 255}, {841, 123}};
  cout << s.minRefuelStops(target, startFuel, stations) << endl;
  return 0;
}
