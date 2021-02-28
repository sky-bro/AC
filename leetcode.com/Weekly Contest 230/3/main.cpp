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
#ifdef SKY_DEBUG
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
private:
    int m, n;
    int dfs(int d, vector<int> &vs, int i, int r, int step) {
        if (i == 0) {
            if (d == 0) return step;
            return INT32_MAX;
        }
        int c = min(vs[i] + r, d / i);
        int res = INT32_MAX;
        for (int j = 0; j < 3 && c >= 0; ++j, --c) {
            int cur = dfs(d-i*c, vs, i-1, vs[i]+r-c, step + c);
            res = min(res, cur);
        }
        return res;
    }
public:
    int minOperations(vector<int>& A, vector<int>& B) {
        m = A.size(), n = B.size();
        if (m > 6*n || n > 6*m) return -1;
        vector<int> cnt1(7), cnt2(7);
        for (int a: A) ++cnt1[a];
        for (int b: B) ++cnt2[b];
        int sA = 0, sB = 0;
        for (int i = 1; i <= 6; ++i) {
            sA += cnt1[i]*i;
            sB += cnt2[i]*i;
        }
        if (sA == sB) return 0;
        if (sA > sB) {
            swap(sA, sB);
            swap(cnt1, cnt2);
        }
        int d = sB - sA;
        vector<int> vs(7);
        for (int i = 5; i >= 1; --i) {
            vs[i] = cnt1[6-i] + cnt2[i+1];
        }
        int res = d;
        int c = min(vs[5], d / 5);
        for (int j = 0; j < 3 && c >= 0; ++j, --c) {
            int cur = dfs(d-5*c, vs, 4, vs[5] - c, c);
            if (cur < res) res = cur;
        }
        return res;
    }
};
