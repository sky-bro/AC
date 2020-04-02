#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// 向量OA叉積向量OB。大於零表示從OA到OB為逆時針旋轉。
int cross(const vector<int>& o, const vector<int>& a, const vector<int>& b) {
  return (a[0] - o[0]) * (b[1] - o[1]) - (a[1] - o[1]) * (b[0] - o[0]);
}

// 小於。依座標大小排序，先排 x 再排 y。
bool compare_position(const vector<int>& a, const vector<int>& b) {
  return (a[0] < b[0]) || (a[0] == b[0] && a[1] < b[1]);
}

// Convex hull，返回线上所有点，所有点在一条线上
class Solution {
 public:
  vector<vector<int>> outerTrees(vector<vector<int>>& points) {
    int n = points.size();
    // 对于单一点的情况
    // if (n <= 1) return points;
    // 只有两个点实际上也可以直接返回
    if (n <= 2) return points;
    vector<vector<int>> res(2 * n);
    sort(points.begin(), points.end(), compare_position);
    int m = 0;

    // 包下半部
    for (int i = 0; i < n; ++i) {
      // 掃除凹陷的點
      while (m >= 2 && cross(res[m - 2], res[m - 1], points[i]) < 0) m--;
      // 添加新的點
      res[m++] = points[i];
    }

    if (m == n) {
      res.resize(m);
      return res;
    }

    // 包上半部，不用再包入方才包過的終點，但會再包一次起點
    for (int i = n - 2, t = m + 1; i >= 0; --i) {
      // 掃除凹陷的點
      while (m >= t && cross(res[m - 2], res[m - 1], points[i]) < 0) m--;
      // 添加新的點
      res[m++] = points[i];
    }

    m--;  // 最後一個點是重複出現的起點，故要減一。
    // 如果m超出了n，说明所有点在一条直线上。。
    // res.resize(min(m, n));
    res.resize(m);
    return res;
  }
};