#include <bits/stdc++.h>
using namespace std;
int __fastio = []() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } ();

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& A) {
        sort(A.begin(), A.end());
        int n = A.size();
        int pre = 0;
        for (int i = 0; i < n; ++i) {
            if (A[i] - pre >= 1) pre += 1;
        }
        return pre;
    }
};
