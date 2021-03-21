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

class Solution {
private:
    int res;
    int n;
    void dfs(int i, int j, int cur, vector<bool> &vis, vector<vector<int>> &D) {
        if (i == 0) {
            res = max(res, cur);
            return;
        }
        for (; j < D.size(); ++j) {
            auto &v = D[j];
            if (vis[v[1]] || vis[v[2]]) continue;
            int ii = (i+1)*i/2;
            if (ii * v[0] + cur <= res) return;
            vis[v[1]] = vis[v[2]] = true;
            dfs(i-1, j + 1, cur + i*v[0], vis, D);
            vis[v[1]] = vis[v[2]] = false;
        }
    }
public:
    int maxScore(vector<int>& A) {
        n = A.size();
        vector<bool> vis(n);
        vector<vector<int>> D;
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j)
                D.push_back({gcd(A[i], A[j]), i, j});
        }
        sort(D.rbegin(), D.rend());
        res = 0;
        dfs(n/2, 0, 0, vis, D);
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> A = {2069,2663,1087,2423,547,1871,1327,2069,2663,1087,2423,547,1871,1327};
    cout << s.maxScore(A) << endl;
    return 0;
}

