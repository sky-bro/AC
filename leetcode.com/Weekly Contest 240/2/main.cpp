#include <bits/stdc++.h>
using namespace std;
int __fastio = []() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } ();

class Solution {
public:
    int maxDistance(vector<int>& A, vector<int>& B) {
        int n1 = A.size(), n2 = B.size();
        int res = 0;
        int i = 0, j = 0;
        for (; i < n1 && j < n2; ++i) {
            if (j < i) j = i;
            if (j >= n2) break;
            while (j < n2 && A[i] <= B[j]) {
                res = max(res, j-i);
                ++j;
            }
        }
        return res;
    }
};
