#include <bits/stdc++.h>
using namespace std;
int __fastio = []() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } ();

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res;
        int i1 = 0, i2 = 0, n1 = A.size(), n2 = B.size();
        while (i1 < n1 && i2 < n2) {
            int l = max(A[i1][0], B[i2][0]), r = min(A[i1][1], B[i2][1]);
            if (l <= r) res.push_back({l, r});
            if (A[i1][1] <= B[i2][1]) ++i1;
            else ++i2;
        }
        return res;
    }
};
