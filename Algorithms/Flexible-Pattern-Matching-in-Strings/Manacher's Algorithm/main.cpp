#include <bits/stdc++.h>
using namespace std;

// odd length
/**
 * @brief find the longest palindromic substring in s with an odd length
 * 
 * @param s the given string
 * @return vector<int> dp, dp.size() == s.size(), dp[i] = the longest palindromic substring length (centered with s[i]) / 2 + 1
 */
vector<int> manacher1(string s) {
    // current max covered idx
    int mx = 0, idx;
    int n = s.size();
    // a b [c] b a a
    // 1 1  3  1 1 1 
    vector<int> dp(n);
    for (int i = 0; i < n; ++i) {
        if (i < mx) dp[i] = min(dp[2*idx-i], mx - i);
        for (; i + dp[i] < n && i - dp[i] >= 0 && s[i + dp[i]] == s[i - dp[i]]; ++dp[i]);
        if (i + dp[i] > mx) {
            mx = i + dp[i];
            idx = i;
        }
    }
    return dp;
}

// even length
/**
 * @brief find the longest palindromic substring in s with an even length
 * 
 * @param s the given string
 * @return vector<int> dp, dp.size() == s.size(), dp[i] = the longest palindromic substring length (centered with s[i-1..i]) / 2
 */
vector<int> manacher2(string s) {
    // current max covered idx
    int mx = 0, idx;
    int n = s.size();
    // a b c b a [a]
    // 0 0 0 0 0  1
    vector<int> dp(n);
    for (int i = 1; i < n; ++i) {
        if (i < mx) dp[i] = min(dp[2*idx-i], mx - i);
        for (; i + dp[i] < n && i - dp[i] - 1 >= 0 && s[i + dp[i]] == s[i - dp[i] - 1]; ++dp[i]);
        if (i + dp[i] > mx) {
            mx = i + dp[i];
            idx = i;
        }
    }
    return dp;
}

// both
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
