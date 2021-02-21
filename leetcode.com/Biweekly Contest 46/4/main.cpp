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

/*
[9,16,30,23,33,35,9,47,39,46,16,38,5,49,21,44,17,1,6,37,49,15,23,46,38,9,27,3,24,1,14,17,12,23,43,38,12,4,8,17,11,18,26,22,49,14,9]
[[17,0],[30,17],[41,30],[10,30],[13,10],[7,13],[6,7],[45,10],[2,10],[14,2],[40,14],[28,40],[29,40],[8,29],[15,29],[26,15],[23,40],[19,23],[34,19],[18,23],[42,18],[5,42],[32,5],[16,32],[35,14],[25,35],[43,25],[3,43],[36,25],[38,36],[27,38],[24,36],[31,24],[11,31],[39,24],[12,39],[20,12],[22,12],[21,39],[1,21],[33,1],[37,1],[44,37],[9,44],[46,2],[4,46]]
*/

class Solution {
    private:
    vector<unordered_set<int>> d;
    int n;
    vector<unordered_set<int>> G;
    vector<int> res;
    vector<int> V;
    void dfs0(int r) {
        for (int nr: G[r]) {
            G[nr].erase(r);
            dfs0(nr);
        }
    }
    void dfs(int r, unordered_map<int,pair<int,int>> &vis, int dep) {
        int mx = -1, v = -1;
        if (dep) for (int p: d[V[r]]) { // coprime
            if (vis.count(p)) {
                if (vis[p].second > mx) v = vis[p].first, mx = vis[p].second;
            }
        }
        res[r] = v;
        bool ok = false;
        if (vis.count(V[r])) ok = true;
        auto bak = vis[V[r]];
        vis[V[r]] = make_pair(r, dep);
        for (int nr: G[r]) {
            dfs(nr, vis, dep+1);
        }
        if (ok) vis[V[r]] = bak;
        else vis.erase(V[r]);
    }
public:
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        V = nums;
        n = nums.size();
        G.clear();
        G.resize(n);
        res.resize(n);
        for (auto &p: edges) {
            G[p[0]].insert(p[1]);
            G[p[1]].insert(p[0]);
        }
        dfs0(0);
        d.clear();
        d.resize(51);
        for (int i = 1; i <= 50; ++i) {
            for (int j = 1; j <= 50; ++j) {
                if (gcd(i, j) == 1) d[i].insert(j);
            }
        }
        unordered_map<int, pair<int,int>> vis;
        dfs(0, vis, 0);
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums = {2,3,3,2};
    vector<vector<int>> edges = {{0,1},{1,2},{1,3}};
    nums = {36,49,26,50,23,41,1,33,7,8,26,14,43,49,21,36,2,11,33,8,34,20,11,12,39,46,4,47,31,33,38,39,13,14,1,5,4,44,3,13,25,34,2,40,35,4,13,37,12,26,27,5,7,1,42,44,41,43,43,8,50,8,44,40,11,1,17,34,25,8,14,9,19,6,44,38,49,50,27,50,25,10,1,41,30,5,26,38,6,48,40,13,11,44,44,14,48,16,3,24,4,26,36,7,35,50,34,32};
    edges = {{99,0},{64,99},{91,64},{55,91},{94,0},{37,94},{58,37},{10,58},{6,10},{56,10},{45,56},{36,45},{40,45},{49,56},{101,49},{39,37},{69,39},{30,69},{34,30},{71,39},{98,39},{31,98},{22,31},{102,22},{3,98},{107,3},{50,107},{18,50},{16,18},{85,107},{15,85},{67,107},{42,67},{72,67},{12,67},{79,12},{53,79},{41,53},{68,53},{59,53},{78,59},{5,59},{105,5},{103,105},{24,79},{70,24},{4,70},{33,70},{54,70},{13,70},{46,13},{74,46},{93,74},{90,93},{1,90},{32,1},{52,1},{38,90},{57,38},{95,90},{14,95},{75,14},{66,75},{97,95},{2,97},{86,97},{25,97},{100,25},{61,100},{8,61},{104,93},{80,104},{82,104},{19,74},{81,19},{62,81},{87,81},{48,87},{77,48},{51,77},{7,81},{63,7},{27,63},{26,63},{28,26},{84,7},{11,84},{20,7},{89,20},{92,20},{76,92},{44,92},{83,44},{65,19},{47,65},{60,47},{23,60},{43,23},{21,43},{17,21},{35,23},{9,35},{29,9},{73,29},{88,60},{96,65},{106,19}};
    s.getCoprimes(nums, edges);
    return 0;
}
