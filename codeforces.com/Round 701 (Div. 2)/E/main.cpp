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

const int N = 2e5+5;
int A[N];
ll V[N], dp[N];

ll run_case() {
    int n;
    cin >> n;
    vector<unordered_set<int>> t(n+1);
    for (int i = 2; i <= n; ++i) {
        cin >> A[i];
        t[i].insert(A[i]);
        t[A[i]].insert(i);
    }
    for (int i = 2; i <= n; ++i) {
        cin >> V[i];
    }
    memset(dp, 0, sizeof(int)*(n+1));
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        unordered_map<int, int> children; // child: parent
        ll mx1 = INT64_MIN, mx2 = INT64_MIN, mn = 1e9+1, mx = 0;
        for (int sz = q.size(); sz; --sz) {
            int v = q.front(); q.pop();
            for (int vv: t[v]) {
                q.push(vv);
                children.emplace(vv, v);
                t[vv].erase(v);
                mx1 = max(dp[v] - V[vv], mx1);
                mx2 = max(dp[v] + V[vv], mx2);
                mn = min(mn, V[vv]);
                mx = max(mx, V[vv]);
            }
        }
        for (auto p: children) {
            dp[p.first] = max(dp[p.second] + max(abs(V[p.first] - mx), abs(V[p.first] - mn)), max(mx1 + V[p.first], mx2 - V[p.first]));
        }
    }
    ll res = 0;
    for (int i = 2; i <= n; ++i) res = max(res, dp[i]);
    return res;
}

int main(int argc, char const *argv[]) {
    int T;
    cin >> T;
    while (T--) {
        cout << run_case() << endl;
    }
    return 0;
}
