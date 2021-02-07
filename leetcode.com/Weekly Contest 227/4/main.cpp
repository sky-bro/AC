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
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        ll res = min(abs(goal), abs(goal-nums[0]));
        if (n == 1) return res;
        set<ll> L;
        for (int i = 0; i < 1 << (n/2); ++i) {
            int sum = 0;
            for (int t = i, j = 0; t; t>>=1, ++j) {
                if (t & 1) sum += nums[j];
            }
            L.insert(sum);
        }
        for (int i = 0; i < 1 << (n - n/2); ++i) {
            // closest to 0
            int a = 0;
            for (int t = i, j = n/2; t; t>>=1, ++j) {
                if (t & 1) a += nums[j];
            }
            auto it = L.lower_bound(goal-a);

            if (it == L.end()) {
                res = min(res, abs((*prev(it)) + a-goal));
            } else if (it == L.begin()) {
                res = min(res, abs((*it) + a-goal));
            } else {
                res = min(res, min(abs((*it) + a-goal), abs((*prev(it)) + a-goal)));
            }
        }
        return res;
    }
};

// from wifiii, same idea, but much cleaner
// class Solution {
// public:
//     int minAbsDifference(vector<int>& a, int b) {
//         int n = a.size(), m = n / 2, r = n - m;
//         int ans = 2e9;
//         vector<int> va, vb;
//         for(int i=0;i<1<<m;++i) {
//             int tmp=0;
//             for(int j=0;j<m;++j) {
//                 if(i>>j&1) tmp+=a[j];
//             }
//             ans=min(ans,abs(tmp-b));
//             va.push_back(tmp);
//         }
//         sort(va.begin(), va.end());
//         for(int i=0;i<1<<r;++i) {
//             int tmp=0;
//             for(int j=0;j<r;++j) {
//                 if(i>>j&1) tmp+=a[j+m];
//             }
//             ans=min(ans,abs(tmp-b));
//             int k=b-tmp;
//             int pos=lower_bound(va.begin(), va.end(), k)-va.begin();
//             for(int j=pos-1;j<=pos+1;++j) {
//                 if(j>=0 && j<va.size()) {
//                     ans=min(ans, abs(va[j]+tmp-b));
//                 }
//             }
//         }
//         return ans;
//     }
// };

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums = {5,-7,3,5};
    int g = 6;
    cout << s.minAbsDifference(nums, g) <<endl;
    return 0;
}

