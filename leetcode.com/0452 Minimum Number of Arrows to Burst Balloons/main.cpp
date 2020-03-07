#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
 public:
  int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(), points.end(),
         [](const vector<int>& a, const vector<int>& b) {
           return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
         });
    int n = points.size(), res = 0;
    for (int i = 0; i < n; ++res) {
      for (int end = points[i][1]; i < n && points[i][0] <= end; ++i)
        end = min(points[i][1], end);
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<vector<int>> points = {{3, 9}, {7, 12}, {3, 8}, {6, 8}, {9, 10},
                                {2, 9}, {0, 9},  {3, 9}, {0, 6}, {2, 8}};
  cout << s.findMinArrowShots(points) << endl;
  return 0;
}
