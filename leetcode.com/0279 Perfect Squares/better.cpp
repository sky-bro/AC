#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

// ref: https://leetcode.com/problems/perfect-squares/discuss/317378/Java-3-solutions-BFS-DP-Maths-with-explanation
/*
// think this is the best
// ref: https://leetcode.com/problems/perfect-squares/discuss/314908/C%2B%2B-0ms-beat-100

class Solution {
public:
    int numSquares(int n) {
        while ((n & 3) == 0) {
            n >>= 2;  
        }
        if ((n & 7) == 7)  return 4;
        if(n < 4) return n;
        int end = sqrt(n);
        if(end * end == n) return 1;
        for(int i = 1; i<= end; ++i) {
            int remain = n - i*i;
            int possible= sqrt(remain);
            if(possible* possible == remain) return 2;
        }
        return 3;
    }
};
*/
// math is awesome!
// Lagrange's Four Square theorem: https://en.wikipedia.org/wiki/Lagrange%27s_four-square_theorem
class Solution {
private:
    bool isSqrt(int n) {
        int m = sqrt(n);
        return m*m == n;
    }
public:
    int numSquares(int n) {
        // case 1:
        if (isSqrt(n)) return 1;

        // case 2:
        for (int i = 1; i * i < n; ++i) {
            if (isSqrt(n-i*i)) return 2;
        }

        for (; (n & 3) == 0; n >>= 2);
        if ((n & 7) == 7) return 4; // case 4
        else return 3; // case 3
    }
};