#include <bits/stdc++.h>
using namespace std;
int __fastio = []() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } ();

// ref: http://web.ntnu.edu.tw/~algo/ConvexHull.html#2

// 时间复杂度: O(MN), M是凸包点的个数，N是所有点的个数

// P為平面上散佈的點。設定為10點。
// CH為凸包上的頂點。設定為逆時針方向排列。
struct Point {int x, y;} P[10], CH[10];
 
// 小於。用以找出最低最左邊的點。
bool compare(Point a, Point b)
{
    return (a.y < b.y) || (a.y == b.y && a.x < b.x);
}
 
// 向量OA叉積向量OB。大於零表示從OA到OB為逆時針旋轉。
int cross(Point o, Point a, Point b)
{
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}
 
// 兩點距離的平方
int length2(Point a, Point b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
 
// 以o點作為中心點，a點比較遠，b點比較近。
bool far(Point o, Point a, Point b)
{
    return length2(o, a) > length2(o, b)
}
 
void Jarvis_march()
{
    // 起點必須是凸包上的頂點。這裡用最低最左邊的點作為起點。
    int start = 0;
    for (int i=0; i<10; ++i)
        if (compare(P[i], P[start]))
            start = i;
 
    // 記錄起點
    int m = 0;          // m為凸包頂點數目
    CH[m] = P[start];   // 記錄起點
 
    // 開始包覆，逆時針順序。
    int current = start;    // 當前點
    for (int m=1; true; ++m)
    {
        // 尋找下一個要被包覆的點：
        // 一、找出最外圍的一點。
        // 二、若凸包上多點共線，則找最遠的一點。
        int next = current;
        for (int i=0; i<10; ++i)
        {
            int c = cross(CH[m-1], P[i], P[next]);
            if (c > 0 ||
                c == 0 && far(CH[m-1], P[i], P[next]))
                next = i;
        }
 
        if (next == start) break;   // 繞一圈回到起點了
        CH[m] = P[next];            // 記錄方才找到的點
        current = next;             // 前往下一點
    }
}

