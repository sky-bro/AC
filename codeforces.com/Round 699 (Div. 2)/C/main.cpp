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

int A[100010];
int B[100010];
int C[100010];

void run_case() {
    int n, m;
    cin >> n >> m;
    vector<int> res(m, -1);
    vector<vector<int>> as(n+1);
    vector<int> bs(n+1, -1);
    for (int i = 0; i < n; ++i) cin >> A[i];
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cin >> B[i];
        bs[B[i]] = i;
        if (A[i] == B[i]) continue;
        as[B[i]].push_back(i);
        ++cnt;
    }
    for (int i = 0; i < m; ++i) cin >> C[i];
    int extra = 0;
    for (int i = 0; i < m; ++i) {
        int c = C[i];
        if (as[c].size() == 0) {
            if (~bs[c]) extra = bs[c];
            else extra = -1;
        } else {
            res[i] = extra = (as[c].back());
            as[c].pop_back();
            --cnt;
        }
    }
    if (cnt || (extra==-1)) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    for (int i = 0; i < m; ++i) {
        if (~res[i]) cout << res[i] + 1 << " ";
        else cout << extra + 1 << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[]) {
    int T;
    cin >> T;
    while (T--) {
        run_case();
    }
    return 0;
}
