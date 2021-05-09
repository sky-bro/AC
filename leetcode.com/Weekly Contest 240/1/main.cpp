#include <bits/stdc++.h>
using namespace std;
int __fastio = []() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } ();

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& A) {
        int cnt = 0, res = 0;
        int sz = 200;
        vector<int> dp(sz);
        int x = 1950;
        for (auto &v: A) {
            dp[v[0]-x] += 1;
            dp[v[1]-x] -= 1;
        }
        int S = 0;
        for (int i = 0; i < sz; ++i) {
            S += dp[i];
            if (S > cnt) {
                cnt = S;
                res = i;
            }
        }
        return res + x;
    }
};
