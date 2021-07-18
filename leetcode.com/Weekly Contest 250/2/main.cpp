#include <bits/stdc++.h>
using namespace std;
int __fastio = []() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } ();

class Solution {
public:
    int addRungs(vector<int>& A, int d) {
        int res = 0;
        int b = 0;
        for (int a: A) {
            if (a - b > d) {
                res += (a - b - 1) / d;
            }
            b = a;
        }
        return res;
    }
};
