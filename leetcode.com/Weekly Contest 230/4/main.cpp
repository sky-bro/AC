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
    vector<double> getCollisionTimes(vector<vector<int>>& A) {
        int n = A.size();
        vector<double> res(n);
        int mn = A[n-1][1]; // min speed
        stack<tuple<int,int,double>> stk; // pos, speed, till time
        for (int i = n-1; i >= 0; --i) {
            if (A[i][1] <= mn) {
                mn = A[i][1];
                res[i] = -1.0;
                stk.emplace(A[i][0], A[i][1], 1e6); // till inf time, always this speed
                continue;
            }
            // pp(stk.size());
            while (true) {
                auto p = stk.top();
                if (get<1>(p) >= A[i][1]) {
                    stk.pop();
                    continue;
                }
                double tt = 1.0*(get<0>(p) - A[i][0])/(A[i][1] - get<1>(p));
                if (tt > get<2>(p) || abs(tt - get<2>(p)) <= 1e-5) { // >=
                    stk.pop();
                    continue;
                }
                stk.emplace(A[i][0], A[i][1], res[i] = tt);
                break;
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> A = {
        {1,2},{2,1},{4,3},{7,2}
    };
    A = {
        {3,4},{5,4},{6,3},{9,1}
    };
    pp(s.getCollisionTimes(A));
    return 0;
}

