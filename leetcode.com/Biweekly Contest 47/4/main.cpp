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
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        vector<int> v(n);
        map<pair<int,int>,int> mp;
        for (auto &e: edges) {
            ++v[--e[0]];
            ++v[--e[1]];
            if (e[0] > e[1]) swap(e[0], e[1]);
            ++mp[{e[0], e[1]}];
        }
        auto d = v;
        sort(v.begin(), v.end());
        vector<int> res;
        for (int x: queries) {
            int cur = 0;
            for (int i = 0, j = n - 1; i < n; ++i) {
                for (; j >= 0 && v[i] + v[j] > x; --j);
                cur += n - j - 1;
            }
            for (int i = 0; i < n; ++i) if (d[i] * 2 > x) --cur;
            cur >>= 1;
            for (auto &[k, vv]: mp) {
                if (d[k.first] + d[k.second] > x && d[k.first] + d[k.second] <= x + vv) --cur;
            }
            res.push_back(cur);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    int n = 4;
    vector<vector<int>> e = {{1,2},{2,4},{1,3},{2,3},{2,1}};
    vector<int> q = {2,3};
    pp(s.countPairs(n, e, q));
    return 0;
}