#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        if (A > E) return computeArea(E, F, G, H, A, B, C, D);
        // case 1. no overlap
        int area1 = (C-A)*(D-B), area2 = (G-E)*(H-F);
        if (C <= E || D <= F || B >= H) {
            return area1 + area2;
        }
        // case 2. first rect enclose the second
        if (B <= F && D >= H && C >= G) {
            return area1;
        }
        // case 3. second rect enclose the first
        if (E <= A && B >= F && D <= H && C <= G) {
            return area2;
        }
        // case 4. minus overlapping area
        int x1 = E, y1 = max(B, F), x2 = min(C, G), y2 = min(D, H);
        return area1 - (y2-y1)*(x2-x1) + area2;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout<<s.computeArea(-2, -2, 2, 2, -3, -3, 3, -1)<<endl;
    return 0;
}
