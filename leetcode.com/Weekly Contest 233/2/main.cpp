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

typedef long long ll;
const int MOD = 1e9 + 7;
class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& A) {
        map<int, int> m1, m2; // buy, sell
        for (auto &v: A) {
            if (v[2]) { // sell
                while (v[1] && !m1.empty() && -m1.begin()->first >= v[0]) {
                    int cnt = min(m1.begin()->second, v[1]);
                    m1.begin()->second -= cnt;
                    v[1] -= cnt;
                    if (m1.begin()->second == 0) {
                        m1.erase(m1.begin());
                    }
                    
                }
                if (v[1]) {
                    m2[v[0]] += v[1];
                }
            } else { // buy
                while (v[1] && !m2.empty() && m2.begin()->first <= v[0]) {
                    int cnt = min(m2.begin()->second, v[1]);
                    m2.begin()->second -= cnt;
                    v[1] -= cnt;
                    if (m2.begin()->second == 0) {
                        m2.erase(m2.begin());
                    }
                    
                }
                if (v[1]) {
                    m1[-v[0]] += v[1];
                }
            }
        }
        ll res = 0;
        for (auto &p: m1) {
            res = (res + p.second) % MOD;
        }
        for (auto &p: m2) {
            res = (res + p.second) % MOD;
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> A = {
        {10,5,0},{15,2,1},{25,1,1},{30,4,0}
    };
    cout << s.getNumberOfBacklogOrders(A) << endl;
    return 0;
}

