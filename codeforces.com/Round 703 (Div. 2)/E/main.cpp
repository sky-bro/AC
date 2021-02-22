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

const int N = 1e5+5;
int m, n;
int main(int argc, char const *argv[]) {
    cin >> n >> m;
    // (x, in/out, val)->id // x->(in/out)->v->id
    vector<vector<unordered_map<int,int>>> ids(n+1, vector<unordered_map<int, int>>(2)); // 0(out): x->id, 1(in): x<-id
    int id = n;
    vector<unordered_map<int,int>> G(n+1+m*4);
    // id->(x, val)
    unordered_map<int, pair<int,int>> id2xv;
    for (int i = 0; i < m; ++i) {
        int a, b, v;
        cin >> a >> b >> v;
        // a->id/(b, out, v)
        if (!ids[b][0][v]) {
            ids[b][0][v] = ++id;
            id2xv[ids[b][0][v]] = make_pair(b, v);
        }
        G[a][ids[b][0][v]] = v*v;

        // a<-id/(b, in, v)
        if (!ids[b][1][v]) ids[b][1][v] = ++id;
        G[ids[b][1][v]][a] = v*v;

        // b->id/(a, out, v)
        if (!ids[a][0][v]) {
            ids[a][0][v] = ++id;
            id2xv[ids[a][0][v]] = make_pair(a, v);
        }
        G[b][ids[a][0][v]] = v*v;

        // b<-id/(a, in, v)
        if (!ids[a][1][v]) ids[a][1][v] = ++id;
        G[ids[a][1][v]][b] = v*v;
    }

    // solve, dijkstra
    priority_queue<pair<int,int>> q; // (-v, x)
    q.emplace(0, 1);
    vector<bool> vis(id+1);
    vector<int> res(id+1, -1);
    res[1] = 0;
    while (!q.empty()) {
        auto vx = q.top(); q.pop();
        vis[vx.second] = true;
        if (vx.second > n && G[vx.second].empty()) {
            // a->id1(b, out, v1)->id2(b, in, v2)->c
            const auto &id1 = id2xv[vx.second]; // (x, v)
            for (auto &id2: ids[id1.first][1]) { // (v,id)
                int d = 2*id1.second*id2.first - vx.first;
                int x = id2.second;
                if (!vis[id2.second] && (res[x] == -1 || res[x] > d)) {
                    q.emplace(-d, x);
                    res[x] = d;
                }
            }
        } else {
            for (auto &p2: G[vx.second]) {
                int d = p2.second - vx.first;
                int x = p2.first;
                if (!vis[p2.first] && (res[x] == -1 || res[x] > d)) {
                    q.emplace(-d, x);
                    res[x] = d;
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
