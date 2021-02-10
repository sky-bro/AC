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

const int MAXN = 1e5+5;
void solve() {
    int n, a;
    cin >> n >> a;
    vector<vector<int>> G(n);
    bitset<MAXN> ans; // ans[i] ? 'a' : 'b'
    for (int i = 1; i < n; ++i) {
        int p; cin >> p;
        G[p-1].push_back(i);
    }
    
    queue<int> q;
    q.push(0);
    int D = 0;
    unordered_map<int, int> sz_cnt;
    unordered_map<int, vector<int>> sz2v;
    vector<vector<int>> dep2v(n);
    while (!q.empty()) {
        int sz = q.size();
        ++sz_cnt[sz];
        for (int i = sz; i; --i) {
            int p = q.front(); q.pop();
            sz2v[sz].push_back(p);
            dep2v[D].push_back(p);
            for (int v: G[p]) {
                q.push(v);
            }
        }
        ++D;
    }

    if (a == 0 || a == n) {
        cout << D << endl;
        cout << string(n, a ? 'a' : 'b') << endl;
        return;
    }

    // bounded knapsack problem
    bitset<MAXN> dp;
    dp[0] = 1;
    vector<pair<int,int>> path(a+1);
    for (auto &p: sz_cnt) {
        int remain = min(p.second, a / p.first);
        for (int cnt = 1; remain; cnt <<= 1) {
            if (cnt > remain) cnt = remain;
            remain -= cnt;
            auto change = dp;
            dp |= (dp << p.first * cnt);
            change ^= dp;
            for (int i = change._Find_first(); i <= a; i = change._Find_next(i)) {
                path[i] = make_pair(p.first, cnt);
            }
        }
    }

    if (dp[a]) { // can knapsack
        cout << D << endl;
        for (int j = a; j; ) {
            int cnt = path[j].first * path[j].second;
            for (int i = 0; i < cnt; ++i) {
                ans[sz2v[path[j].first].back()] = 1;
                sz2v[path[j].first].pop_back();
            }
            j -= cnt;
        }
    } else { // greedy
        cout << D + 1 << endl;
        int m = n; // remain nodes
        for (int m = n, d = 0, sz; a; m -= sz, ++d) {
            sz = dep2v[d].size();
            if (sz <= a) {
                // all 'a'
                for (int x: dep2v[d]) ans[x] = 1;
                a -= sz;
            } else if (sz <= m - a) {
                // all 'b', do nothing
            } else {
                // count non-leaf
                int leaf_cnt = 0;
                for (int x: dep2v[d]) {
                    if (G[x].empty()) ++leaf_cnt;
                }
                if (a >= sz - leaf_cnt) {
                    int extra = sz - a;
                    for (int x: dep2v[d]) {
                        if (G[x].empty() && extra) {
                            --extra; // 'b'
                        } else {
                            ans[x] = 1;
                            --a;
                        }
                    }
                } else {
                    int extra = sz - (m-a);
                    for (int x: dep2v[d]) {
                        if (extra) {
                            if (G[x].empty()) {
                                ans[x] = 1;
                                --a;
                                --extra;
                            }
                        } else break;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) cout << (ans[i] ? 'a' : 'b');
}

int main(int argc, char const *argv[]) {
    solve(); cout << endl;
    return 0;
}
