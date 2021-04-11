#include <bits/stdc++.h>
using namespace std;
int __fastio = []() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } ();

class Solution {
public:
    int minSideJumps(vector<int>& A) {
        int n = A.size();
        int dp[3] = {1, 0, 1};
        for (int i = 1; i < n; ++i) {
            if (A[i]) {
                dp[A[i]-1] = 1e7;
            }
            if (A[i]!=1) dp[0] = min(dp[0], min(dp[1] + 1, dp[2] + 1));
            if (A[i]!=2) dp[1] = min(dp[1], min(dp[0] + 1, dp[2] + 1));
            if (A[i]!=3) dp[2] = min(dp[2], min(dp[0] + 1, dp[1] + 1));
        }
        return min(dp[0], min(dp[1], dp[2]));
    }
};
