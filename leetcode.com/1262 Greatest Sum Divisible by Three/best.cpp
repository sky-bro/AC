#include <bits/stdc++.h>
using namespace std;
int __fastio = []() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } ();

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int res = 0, r1 = 1e5, r2 = 1e5, r;
        for (int x: nums) {
            res += x;
            r = x % 3;
            if (r == 1) {
                int rr1 = r1;
                r1 = min(r1, x);
                r2 = min(r2, rr1 + x);
            } else if (r == 2) {
                int rr2 = r2;
                r2 = min(r2, x);
                r1 = min(r1, rr2 + x);
            }
        }
        r = res % 3;
        return r == 0 ? res : (r == 1 ? (res - r1) : (res - r2));
    }
};