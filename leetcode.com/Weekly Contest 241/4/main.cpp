#include <bits/stdc++.h>
using namespace std;
int __fastio = []() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } ();

typedef long long ll;
class Solution {
public:
    int stoneGameVIII(vector<int>& A) {
        int n=A.size();
        vector<ll> acc(n+1);
        for (int i=0; i<n; i++) acc[i+1] = acc[i] + A[i];
        vector<ll> dp(n,0);
        ll ma = acc[n];
        for(int i = n-2; i >= 0; i--){
            dp[i] = ma;
            ma = max(ma,-dp[i] + acc[i+1]);
        }
        return dp[0];
    }
};
