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

const int N = 110;
int A[N*2];
int D[N];
int M[N];
void run_case() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> A[i+n];
        M[A[i+n]] = i;
    }
    for (int i = n-1; i > 0; --i) {
        A[i] = max(A[i<<1], A[i<<1|1]);
    }
    queue<pair<int,int>> q;
    q.push(make_pair(0, n-1));
    int d = 0;
    auto Q = [&](int i, int j) {
        int mx = 0;
        for (i += n, j += n + 1; i < j; i >>= 1, j >>= 1) {
            if (i&1) mx = max(mx, A[i++]);
            if (j&1) mx = max(mx, A[--j]);
        }
        return mx;
    };
    while (!q.empty()) {
        for (int sz = q.size(); sz; --sz) {
            auto p = q.front(); q.pop();
            int rt = Q(p.first, p.second);
            D[rt] = d;
            int m = M[rt];
            if (m > p.first) {
                q.emplace(p.first, m-1);
            }
            if (m < p.second) {
                q.emplace(m+1, p.second);
            }
        }
        ++d;
    }
    for (int i = 0; i < n; ++i) {
        cout << D[A[i+n]] << " ";
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
