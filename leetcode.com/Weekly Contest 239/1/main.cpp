#include <bits/stdc++.h>
using namespace std;
int __fastio = []() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } ();

class Solution {
public:
    int getMinDistance(vector<int>& A, int t, int s) {
        int n = A.size(), res = n;
        for (int i = 0; i < n; ++i) {
            if (A[i] == t) res = min(res, abs(i - s));
        }
        return res;
    }
};
