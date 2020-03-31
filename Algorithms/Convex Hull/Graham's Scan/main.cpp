// ref: http://www.csie.ntnu.edu.tw/~u91029/ConvexHull.html#3
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 10;

// P為平面上散佈的點。設定為10點。
// CH為凸包上的頂點。設定為逆時針方向排列。可以視作一個stack。
struct Point {
  int x, y;
} P[N + 1], CH[N + 1];

// 向量OA叉積向量OB。大於零表示從OA到OB為逆時針旋轉。
int cross(Point o, Point a, Point b) {
  return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

// 小於。用以找出最低最左邊的點。
bool compare_position(Point a, Point b) {
  return (a.y < b.y) || (a.y == b.y && a.x < b.x);
}

/*
// 小於。以P[0]當中心點做角度排序，角度由小排到大（即逆時針方向）。
// 角度相同時，順序隨便。
bool compare_angle(Point a, Point b)
{
    return cross(P[0], a, b) > 0;
}
*/

// 兩點距離的平方
int length2(Point a, Point b) {
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

// 小於。以P[0]當中心點做角度排序，角度由小排到大（即逆時針方向）。
// 角度相同時，距離較離中心點較近的點排前面。
bool compare_angle(Point a, Point b) {
  // 加入角度相同時，距離長度的判斷。
  int c = cross(P[0], a, b);
  return c > 0 || (c == 0 && length2(P[0], a) < length2(P[0], b));
}

void Graham_scan() {
  // 這裡用最低最左邊的點作為起點，並將中心點換到第零點。O(N)
  swap(P[0], *min_element(P, P + N, compare_position));

  // 其餘各點依角度排序。O(NlogN)
  sort(P + 1, P + N, compare_angle);

  // 直接把中心點作為起點，開始包覆，逆時針方向。O(N)
  P[N] = P[0];  // 讓程式方便處理包至最後一點的情況。

  int m = 0;  // m 為凸包頂點數目
  for (int i = 0; i <= N; ++i) {
    // 掃除凹陷的點
    while (m >= 2 && cross(CH[m - 2], CH[m - 1], P[i]) <= 0) m--;
    // 添加新的點
    CH[m++] = P[i];
  }

  m--;  // 最後一個點是重複出現的起點，故要減一。
}