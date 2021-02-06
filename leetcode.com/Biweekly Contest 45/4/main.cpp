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

typedef long long ll;
class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(), events.end(), [](const vector<int>&a, const vector<int>& b){
            return (a[1] == b[1]) ? (a[2] > b[2]) : (a[1] < b[1]);
        });
        map<int, vector<int>> dp;
        int res = 0;
        for (auto &e: events) {
            if (dp.empty()) {
                res = max(res, e[2]);
                dp.emplace(e[1], vector<int>(k, e[2]));
                continue;
            }
            dp[e[1]] = prev(dp.end())->second;
            auto it = dp.lower_bound(e[0]);
            if (it == dp.begin()) { // no previous
                for (int i = 0; i < k; ++i) {
                    dp[e[1]][i] = max(dp[e[1]][i], e[2]);
                }
                res = max(res, e[2]);
            } else {
                --it;
                dp[e[1]][0] = max(dp[e[1]][0], e[2]);
                res = max(res, e[2]);
                for (int i = 1; i < k; ++i) {
                    dp[e[1]][i] = max(dp[e[1]][i], it->second[i-1] + e[2]);
                    res = max(res, dp[e[1]][i]);
                }
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> e = {
        {21,77,43},{2,74,47},{6,59,22},{47,47,38},{13,74,57},{27,55,27},{8,15,8}
    };
    int k = 4;
    e = {
        {19,42,7},{41,73,15},{52,73,84},{84,92,96},{6,64,50},{12,56,27},{22,74,44},{38,85,61}
    };
    k = 5;
    e = {{1,2,4},{3,4,3},{2,3,10}};
    k = 2;
    e = {
        {1,1,1},{2,2,2},{3,3,3},{4,4,4}
    };
    k = 3;
    cout << s.maxValue(e, k) <<endl;
    return 0;
}

