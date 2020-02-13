#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point
{
    int x, y;
    Point(int x_, int y_): x(x_), y(y_) {}
    int operator-(const Point& other) {
        return x - other.x + y - other.y;
    }
};


class Solution {
private:
    int n;
public:
    bool isSelfCrossing(vector<int>& x) {
        n = x.size();
        if (n <= 3) return false;
        Point p0(0, 0), p1(0, 0), p2(0, x[0]), p3(-x[1], x[0]), p4(-x[1], x[0]-x[2]);
        vector<Point> points = {Point(0, 0), Point(0, 0), Point(0, x[0]), Point(-x[1], x[0]), Point(-x[1], x[0]-x[2])};
        int i = 3;
        if (points[4].y < 0)
        for (; i < n; ++i) {
            if ((i&3) == 0) {
                // up
                if (points[0].y > points[4].y + x[i]) {
                    // inner
                    points[0].x = points[4].x;
                    points[0].y = points[4].y + x[i];
                    rotate(points.begin(), points.begin()+1, points.end());
                    ++i;
                    break;
                } else if (points[1].y < points[4].y + x[i]) {
                    // outter
                    points[0].x = points[4].x;
                    points[0].y = points[4].y + x[i];
                    rotate(points.begin(), points.begin()+1, points.end());
                } else {
                    // middle
                    points[2].y = points[4].y;
                    points[2].x = points[0].x;
                    points[3] = points[4];
                    points[4].y += x[i];
                    ++i;
                    break;
                }
            } else if ((i&3) == 1) {
                // left
                if (points[0].x < points[4].x - x[i]) {
                    // inner
                    points[0].y = points[4].y;
                    points[0].x = points[4].x - x[i];
                    rotate(points.begin(), points.begin()+1, points.end());
                    ++i;
                    break;
                } else if (points[1].x > points[4].x - x[i]) {
                    // outter
                    points[0].y = points[4].y;
                    points[0].x = points[4].x - x[i];
                    rotate(points.begin(), points.begin()+1, points.end());
                } else {
                    // middle
                    points[2].x = points[4].x;
                    points[2].y = points[0].y;
                    points[3] = points[4];
                    points[4].x -= x[i];
                    ++i;
                    break;
                }
            } else if ((i&3) == 2) {
                // down
                if (points[0].y < points[4].y - x[i]) {
                    // inner
                    points[0].x = points[4].x;
                    points[0].y = points[4].y - x[i];
                    rotate(points.begin(), points.begin()+1, points.end());
                    ++i;
                    break;
                } else if (points[1].y > points[4].y - x[i]) {
                    // outter
                    points[0].x = points[4].x;
                    points[0].y = points[4].y - x[i];
                    rotate(points.begin(), points.begin()+1, points.end());
                } else {
                    // middle
                    points[2].y = points[4].y;
                    points[2].x = points[0].x;
                    points[3] = points[4];
                    points[4].y -= x[i];
                    ++i;
                    break;
                }
            } else {
                // right
                if (points[0].x > points[4].x + x[i]) {
                    // inner
                    points[0].y = points[4].y;
                    points[0].x = points[4].x + x[i];
                    rotate(points.begin(), points.begin()+1, points.end());
                    ++i;
                    break;
                } else if (points[1].x < points[4].x + x[i]) {
                    // outter
                    points[0].y = points[4].y;
                    points[0].x = points[4].x + x[i];
                    rotate(points.begin(), points.begin()+1, points.end());
                } else {
                    // middle
                    points[2].x = points[4].x;
                    points[2].y = points[0].y;
                    points[3] = points[4];
                    points[4].x += x[i];
                    ++i;
                    break;
                }
            }
        }

        for (; i < n; ++i) {
            if (x[i] >= abs(points[2]-points[3])) {
                return true;
            }
            if ((i&3) == 0) {
                points[1].x = points[4].x;
                points[1].y = points[4].y + x[i];
            } else if ((i&3) == 1) {
                points[1].y = points[4].y;
                points[1].x = points[4].x - x[i];
            } else if ((i&3) == 2) {
                points[1].x = points[4].x;
                points[1].y = points[4].y - x[i];
            } else {
                points[1].y = points[4].y;
                points[1].x = points[4].x + x[i];
            }
            rotate(points.begin()+1, points.begin()+2, points.end());
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> x = {1,1,1,1};
    Solution s;
    x = {2, 1, 1, 2};
    x = {3, 3, 4, 2, 2};
    x = {1,1,2,2,3,1,1};
    x = {1,1,2,2,3,3,4,4,10,4,4,3,3,2,2,1,1};
    cout<<s.isSelfCrossing(x)<<endl;
    return 0;
}
