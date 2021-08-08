#include <bits/stdc++.h>
using namespace std;

vector<int> manacher(string s0) {
    int n0 = s0.size(), n = n0 * 2 + 1;
    char DELIMITER = '#';
    string s = "";
    s.push_back(DELIMITER);
    for (int i = 0; i < n0; ++i) {
        s.push_back(s0[i]);
        s.push_back(DELIMITER);
    }
    // #b#a[#]a#b#: 5
    // #b#[a]#b#:   4
    vector<int> dp(n, 1);
    int mx = 0;
    int idx = 0;
    for (int i = 1; i < n; ++i) {
        if (i < mx) dp[i] = min(dp[2*idx-i], mx - i);
        for (; i + dp[i] < n && i - dp[i] >= 0 && s[i + dp[i]] == s[i - dp[i]]; ++dp[i]);
        if (dp[i] + i > mx) {
            mx = dp[i] + i;
            idx = i;
        }
    }
    return dp;
}
