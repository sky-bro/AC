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

class Solution {
public:
    string longestNiceSubstring(string s) {
        int i = 0, len = 0;
        int n = s.size();
        for (int j = 0; j < n-len; ++j) {
            int flag[26] = {0};
            int cnt = 0;
            for (int k = 0; k < len; ++k) {
                char c = s[j+k];
                if (isupper(c)) {
                    flag[c-'A'] |= 2;
                } else {
                    flag[c-'a'] |= 1;
                }
            }
            for (int k = 0; k < 26; ++k) {
                if (flag[k]) cnt += (flag[k] != 3);
            }
            for (int k = len; j+k < n; ++k) {
                char c = s[j+k];
                if (isupper(c) && flag[c-'A'] != 3) {
                    if (flag[c-'A'] == 0) ++cnt;
                    flag[c-'A'] |= 2;
                    if (flag[c-'A'] == 3) --cnt;
                } else if (flag[c-'a'] != 3) {
                    if (flag[c-'a'] == 0) ++cnt;
                    flag[c-'a'] |= 1;
                    if (flag[c-'a'] == 3) --cnt;
                }
                if (cnt == 0) {
                    i = j;
                    len = k + 1;
                }
            }

        }
        return s.substr(i, len);
    }
};
