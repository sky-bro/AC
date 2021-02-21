// =========== Template ========== //
#include <bits/stdc++.h>
using namespace std;
int __fastio = []() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } ();
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p);
template<typename A> ostream& operator<<(ostream &os, const set<A> &m) { os << "{"; string sep = ""; for (auto e: m) os << sep << e, sep = ", "; return os << "}"; }
template<typename A> ostream& operator<<(ostream &os, const multiset<A> &m) { os << "{"; string sep = ""; for (auto e: m) os << sep << e, sep = ", "; return os << "}"; }
template<typename A, typename B> ostream& operator<<(ostream &os, const map<A, B> &m) { os << "{"; string sep = ""; for (auto e: m) os << sep << e.first << ": " << e.second, sep = ", "; return os << "}"; }
template<typename T>ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; string sep = ""; for (auto e: v) os << sep << e, sep = ", "; return os << "]"; }
template<typename T, size_t L>ostream& operator<<(ostream& os, const array<T, L>& v) { os << "["; string sep = ""; for (int i = 0; i < L; ++i) os << sep << v[i], sep = ", "; return os << "]"; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef DEBUG
#define pp(...) cerr << "\t[" << #__VA_ARGS__ << "]:\t", dbg_out(__VA_ARGS__)
#define ppp(x) cerr << x << "\n"
#else
#define pp(...)
#define ppp(...)
#endif
template<class Fun> class y_combinator_result { Fun fun_; public: template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {} template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); } };
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
#define yc y_combinator
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
#define fi first
#define se second
#define sz(x) (int((x).size()))
#define data _data

const int N = 1010;
int dp[N][N], dp2[N][N], dp3[N][N];
int LCS2(string & str1, int len1, string & str2, int len2)
{
    dp[0][0] = 0;
    int res = 0;
    for (int i = 1; i <= len1; ++i)
    {
        for (int j = 1; j <= len2; ++j)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (i < len1 || j < len2) {
                    res = max(res, dp[i][j]*2+max(dp2[i][len1-1], dp3[j][len2-1]));
                } else {
                    res = max(res, dp[i][j]*2);
                }
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i][j - 1];
            }
        }
    }
    return res;
}

class Solution {
public:
    int longestPalindrome(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        for (int i = 0; i < n1; ++i) {
            dp2[i][i] = 1;
        }
        for (int i = n1 - 1; i >= 0; --i) {
            for (int j = i + 1; j < n1; ++j) {
                if (word1[i] == word1[j]) {
                    dp2[i][j] = 2;
                    if (i + 1 <= j - 1) {
                        dp2[i][j] += dp2[i+1][j-1];
                    }
                } else {
                    dp2[i][j] = max(dp2[i][j-1], dp2[i+1][j]);
                }
            }
        }
        reverse(word2.begin(), word2.end());

        for (int i = 0; i < n2; ++i) {
            dp3[i][i] = 1;
        }
        for (int i = n2 - 1; i >= 0; --i) {
            for (int j = i + 1; j < n2; ++j) {
                if (word2[i] == word2[j]) {
                    dp3[i][j] = 2;
                    if (i + 1 <= j - 1) {
                        dp3[i][j] += dp3[i+1][j-1];
                    }
                } else {
                    dp3[i][j] = max(dp3[i][j-1], dp3[i+1][j]);
                }
            }
        }

        return LCS2(word1, n1, word2, n2);
    }
};

int main(int argc, char const *argv[])
{
    string s1 = "eeeecd", s2 = "eabfbeeb";
    Solution s;
    cout << s.longestPalindrome(s1, s2) << endl;
    return 0;
}

