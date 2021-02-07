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

char G[1001][1001];

void run_case() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> G[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (G[i][j] == G[j][i]) {
                cout << "YES\n";
                for (int k = 0; k <= m; ++k) {
                    cout << ((k & 1) ? (i+1) : (j+1)) << " ";
                }
                cout << endl;
                return;
            }
        }
    }

    if (m & 1) { // easy, always YES
        cout << "YES\n";
        for (int i = 0; i <= m; ++i) {
            cout << ((i&1) ? 1 : 2) << " ";
        }
        cout << endl;
    } else {
        if (n == 2) {
            cout << "NO\n";
            return;
        }
        cout << "YES\n";
        int a,b,c;
        if (G[0][1] == G[1][2]) { // 012
            a = 1, b = 2, c= 3;
        } else if (G[1][2] == G[2][0]) { // 120
            a = 2, b = 3, c= 1;
        } else { // 102
            a = 2, b = 1, c= 3;
        }
        int i = 0;
        if (m & 2) {
            cout << a << " ";
            for (; i < m/2; ++i) {
                cout << ((i & 1) ? a : b) << " ";
            }
            for (; i < m; ++i) {
                cout << ((i & 1) ? c : b) << " ";
            }
        } else {
            cout << b << " ";
            for (; i < m/2; ++i) {
                cout << ((i & 1) ? b : a) << " ";
            }
            for (; i < m; ++i) {
                cout << ((i & 1) ? b : c) << " ";
            }
        }
        cout << endl;
    }
}

int main(int argc, char const *argv[]) {
    int T;
    cin >> T;
    while (T--) {
        run_case();
    }
    return 0;
}
