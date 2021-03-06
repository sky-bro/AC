// =========== Template ========== //
#include <bits/stdc++.h>
using namespace std;
int __fastio = []() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } ();
template<typename A> ostream& operator<<(ostream &os, const set<A> &m) { os << "{"; string sep = ""; for (auto e: m) os << sep << e, sep = ", "; return os << "}"; }
template<typename A> ostream& operator<<(ostream &os, const multiset<A> &m) { os << "{"; string sep = ""; for (auto e: m) os << sep << e, sep = ", "; return os << "}"; }
template<typename A, typename B> ostream& operator<<(ostream &os, const map<A, B> &m) { os << "{"; string sep = ""; for (auto e: m) os << sep << e.first << ": " << e.second, sep = ", "; return os << "}"; }
template<typename T>ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; string sep = ""; for (auto e: v) os << sep << e, sep = ", "; return os << "]"; }
template<typename T, size_t L>ostream& operator<<(ostream& os, const array<T, L>& v) { os << "["; string sep = ""; for (int i = 0; i < L; ++i) os << sep << v[i], sep = ", "; return os << "]"; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
template<typename...Ts> ostream& operator<<(ostream &os, const tuple<Ts...> &t) { os << '('; apply([&os](Ts const&...args) { size_t i = 0, n = sizeof...(Ts); ((os << args << (++i != n ? ", " : "")), ...); }, t); return os << ')'; }
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

const int MOD = 1e9 + 7;
typedef long long ll;
class Solution {
private:
    int n;
    vector<unordered_map<int,int>> G;

    int dfs(int i, vector<int> &dp, vector<int> &d) {
        if (i == n-1) return 1;
        if (~dp[i]) return dp[i];
        ll res = 0;
        for (auto &child: G[i]) {
            if (d[child.first] >= d[i]) continue;
            res = (res + dfs(child.first, dp, d)) % MOD;
        }
        return dp[i] = res;
    }
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        if (n == 1) return 1; // ?
        this->n = n;
        G.clear();
        G.resize(n);
        for (auto &e: edges) {
            G[--e[0]].emplace(--e[1], e[2]);
            G[e[1]].emplace(e[0], e[2]);
        }
        vector<int> dis(n, -1);
        vector<bool> vis(n);
        priority_queue<pair<int, int>> pq; // {-weight, label}
        pq.emplace(0, n-1);
        dis[n-1] = 0;
        while (!pq.empty()) {
            auto p = pq.top(); pq.pop();
            vis[p.second] = true;
            for (auto child: G[p.second]) {
                int v = child.first;
                int d = child.second - p.first;
                if (vis[v]) continue;
                if (dis[v] == -1 || dis[v] > d) {
                    pq.emplace(-d, v);
                    dis[v] = d;
                }
            }
        }

        vector<int> dp(n, -1);
        return dfs(0, dp, dis);
    }
};
