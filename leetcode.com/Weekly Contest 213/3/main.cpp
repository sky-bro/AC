#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

class Solution {
 public:
  int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
    priority_queue<int> gaps;
    int n = heights.size();
    int pre = heights[0];
    int res = 0;
    for (int i = 1; i < n; ++i, ++res) {
      int gap = heights[i] - pre;
      pre = heights[i];
      if (gap <= 0) continue;
      gaps.push(gap);
      bricks -= gap;
      if (bricks >= 0) {
        continue;
      } else if (ladders == 0) {
        break;
      } else {
        while (bricks < 0 && !gaps.empty() && ladders) {
          bricks += gaps.top();
          gaps.pop();
          --ladders;
        }
        if (bricks < 0) break;
      }
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  vector<int> heights = {4, 2, 7, 6, 9, 14, 12};
  int bricks = 5;
  int ladders = 1;

  heights = {4, 12, 2, 7, 3, 18, 20, 3, 19};
  bricks = 10;
  ladders = 2;
  Solution s;
  cout << s.furthestBuilding(heights, bricks, ladders) << endl;
  return 0;
}
