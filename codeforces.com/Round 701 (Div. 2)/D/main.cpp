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

int m, n;
int A[505][505];
int B[505][505];
int K[32];

// TLE
bool solve(int i, int j, unordered_set<int> &Ks) {
    if (j == n) {
        j = 0;
        ++i;
    }
    if (i == m) return true;
    if (i == 0) {
        // left
        for (int k = 1; k < 32; ++k) {
            int b = B[i][j-1] - K[k];
            if (b < A[i][j]) break;
            if (b % A[i][j]) continue;
            B[i][j] = b;
            if (solve(i, j + 1, Ks)) return true;
        }
        for (int k = 1; k < 32; ++k) {
            int b = B[i][j-1] + K[k];
            if (b > 1000000) break;
            if (b % A[i][j]) continue;
            B[i][j] = b;
            if (solve(i, j + 1, Ks)) return true;
        }
    } else if (j == 0) {
        // up
        for (int k = 1; k < 32; ++k) {
            int b = B[i-1][j] - K[k];
            if (b < A[i][j]) break;
            if (b % A[i][j]) continue;
            B[i][j] = b;
            if (solve(i, j + 1, Ks)) return true;
        }
        for (int k = 1; k < 32; ++k) {
            int b = B[i-1][j] + K[k];
            if (b > 1000000) break;
            if (b % A[i][j]) continue;
            B[i][j] = b;
            if (solve(i, j + 1, Ks)) return true;
        }
    } else {
        // up & left
        for (int k = 1; k < 32; ++k) {
            int b = B[i-1][j] - K[k];
            if (b < A[i][j]) break;
            if (b % A[i][j]) continue;
            if (Ks.count(abs(B[i][j-1] - b)) == 0) continue;
            B[i][j] = b;
            if (solve(i, j + 1, Ks)) return true;
        }
        for (int k = 1; k < 32; ++k) {
            int b = B[i-1][j] + K[k];
            if (b > 1000000) break;
            if (b % A[i][j]) continue;
            if (Ks.count(abs(B[i][j-1] - b)) == 0) continue;
            B[i][j] = b;
            if (solve(i, j + 1, Ks)) return true;
        }
    }
    return false;
}

int main(int argc, char const *argv[]) {
    for (int i = 1; i < 32; ++i) K[i] = (i*i*i*i);
    unordered_set<int> Ks(K+1, K+32);
    cin >> m >> n;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
    }
    B[0][0] = A[0][0];
    while (!solve(0, 1, Ks)) {
        B[0][0] += A[0][0];
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
