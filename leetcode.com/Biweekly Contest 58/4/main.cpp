#include <bits/stdc++.h>
using namespace std;
int __fastio = []() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } ();


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

typedef long long ll;
class Solution {
public:
    ll maxProduct(string s) {
        vector<int> p = manacher(s);
        int n = p.size();
        vector<ll> d;
        for (int i = 1; i < n; i += 2) {
            d.push_back(p[i] - 1);
        }
        n = d.size();
        vector<ll> d1(n), d2(n);
        for (int i = 0; i < n; ++i) {
            int idx1 = d[i] / 2 + i;
            int idx2 = n - 1 - i - d[n-1-i]/2;
            d1[idx1] = max(d[i], d1[idx1]);
            d2[idx2] = max(d[n-1-i], d2[idx2]);
        }
        for (int i = 1; i < n; ++i) {
            d1[n-1-i] = max(d1[n-1-i], d1[n - i] - 2);
            d2[i] = max(d2[i], d2[i - 1] - 2);
        }
        for (int i = 1; i < n; ++i) {
            d1[i] = max(d1[i], d1[i-1]);
            d2[n-1-i] = max(d2[n-1-i], d2[n-i]);
        }
        
        ll res = 1;
        for (int i = 0; i < n - 1; ++i) {
            res = max(d1[i] * d2[i + 1], res);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    string str = "ababbb";
    str = "zaaaxbbby";
    str = "epmxqygtpncdtrcqghurhexfxehruhgqcrtdcnptgyqxmpeivgditbwbgmnvvnmgbwbtidgvinmoomn";
    str = "ggbswiymmlevedhkbdhntnhdbkhdevelmmyiwsbgg";
    cout << s.maxProduct(str) << endl;
    return 0;
}

