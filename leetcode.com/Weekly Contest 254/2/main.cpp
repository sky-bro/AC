#include <bits/stdc++.h>
using namespace std;
int __fastio = []() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } ();

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& A) {
        int n = A.size();
        // 1 2 3 4 5
        // 1 3 2 4 5
        // [1,3,2,4,6,5,7,8]
        // 1 2 3 4 5 6 7 8
        // 1 3 2 4 6 5
        sort(A.begin(), A.end());
        vector<int> res;
        for (int i = 0, j = n/2; i < n/2; ++j, ++i) {
            res.push_back(A[j]);
            res.push_back(A[i]);
        }
        if (n & 1) res.push_back(A.back());
        return res;
    }
};
