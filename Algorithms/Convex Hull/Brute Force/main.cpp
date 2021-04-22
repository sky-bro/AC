#include <bits/stdc++.h>
using namespace std;

struct Point {
  int x, y;
  bool operator<(const Point& o) {
      return x < o.x || (x == o.x) && y < o.y;
  }
} P[10], CH[10];

// 向量OA叉積向量OB。大於零表示從OA到OB為逆時針旋轉。
double cross(Point o, Point a, Point b) {
  return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

int BruteForceCH() {
    for (int a = 0; a < 10; ++a) {
        if (P[a].x < 0) continue; // Point::x < 0 -> point deleted
        for (int b = 0; b < 10; ++b) {
            if (b == a || P[b].x < 0) continue;
            for (int c = 0; c < 10; ++c) {
                if (c == a || c == b || P[c].x < 0) continue;
                // check if abc on same line, if so, delete the middle point
                if (cross(P[a], P[b], P[c]) == 0) {
                    int i = a, j = b, k = c;
                    if (P[j] < P[i]) swap(i, j);
                    if (P[j] < P[k]) P[j].x = -1;
                    else if (P[i] < P[k]) P[k].x = -1;
                    else P[i].x = -1;
                    continue;
                }
                for (int d = 0; d < 10; ++d) {
                    if (d == a || d == b || d == c || P[d].x < 0) continue;
                    if (cross(P[a], P[b], P[c])*cross(P[a], P[b], P[d]) >= 0
                     && cross(P[a], P[c], P[b])*cross(P[a], P[c], P[d]) >= 0
                     && cross(P[b], P[c], P[a])*cross(P[b], P[c], P[d]) >= 0
                    ) {
                        P[d].x = -1;
                    }
                }
            }
        }
    }
    // A, B
    int a = 0, b = 0;
    for (int i = 1; i < 10; ++i) {
        if (P[a].x > P[i].x) a = i;
        if (P[b].x < P[i].x) b = i;
    }
    CH[0] = P[a];
    Point S_U[10];
    int il = 1, iu = 0;
    // S_L
    // S_U
    for (int i = 0; i < 10; ++i) {
        if (i == a || i == b) continue;
        if (cross(P[a], P[b], P[i]) < 0) { // S_L
            CH[il++] = P[i];
        } else { // S_U
            S_U[iu++] = P[i];
        }
    }
    // A, S_L, B, reverse(S_U)
    sort(CH+1, CH+il);
    sort(S_U, S_U+iu);
    CH[il] = P[b];
    for (int i = 0; i < iu; ++i) CH[il+1+i] = S_U[iu-1-i];
    return il + 1 + iu;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
