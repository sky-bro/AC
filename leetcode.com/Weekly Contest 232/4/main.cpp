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
    int maximumScore(vector<int>& A, int k) {
        int n = A.size();
        A.insert(A.begin(), -1);
        A.push_back(-1);
        int l = k+1, r = k+1;
        int mn = A[k+1];
        int res = A[k+1];
        while (!(l == 0 && r == n+1)) {
            int mx;
            while (A[l] >= mn) --l;
            while (A[r] >= mn) ++r;
            int sz = r - l - 1;
            res = max(mn*sz, res);
            if (A[l] < A[r]) {
                ++l;
                mn = min(mn, A[r]);
            } else if (A[l] > A[r]) {
                --r;
                mn = min(mn, A[l]);
            } else if (l == 0) return res;
            else mn = min(mn, A[r]);
        }
        return res;
    }
};


int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> A = {1,4,3,7,4,5};
    int k = 3;
    A = {2479,5421,7306,2977,8003,5801,1106,4420,6434,8536,68,9100,4808,9033,3206,4540,558,5135,5516,8824,1021,7710,7715,1937,5235,953,9332,5847,1577,5215,7641,6377,583,7034,2284,5041,9118,1947,9645,9841,1499,1420,2778,4172,7624,2954,4637,6392,4759,8968,812,1646,2224,5225,7422,7336,8590,6048,1862,3752,2721,4595,6134,1668,8412,7096,4954,8467,9726,1783,7465,947,8455,4075,2214,1863,7443,4683,137,3667,4333,3825,8971,3141,5537,9274,249,1849,2254,3581,6527,479,8376,1075,8832,1983,3866,7312,7114,5326,2493,2092,7863,321,6490,6087,6385,2624,6813,5669,2824,5492,1454,2970,3264,7663,1645,5237,9992,6605,8145,7825,2726,7582,6466,8366,6739,5605,9705,5100,6729,3958,1122,4680,8611,420,7752,587,7252,6436,3544,8620,1068,1873,325,5462,4027,826,618,6223,461,4002,156,9709,8462,8919,890,5037,7829,1365,5014,5105,1758,1349,7088,3356,4685,2416,2066,6938,8294,2013,2367,9037,7461,6781,1816,5940,2393,6648,1250,209,4077,3579,4418,8166,1067,1592,7790,5234,1672,6066,7318,5246,5950,7494,8836,2710,7379,4881,2868,7693,8172,6296,4797,6785,1278,1031,1216,8886,3395,6536,3693,1408,8577,9721,8841,8957,8155,2249,4424,528,6771,3681,5341,987,7825,6019,4339,5710,2109,5955,4591,1749,4947,1737,7792,6854,4429,8510,5303,7821,2020,5109,2859,4298,7822,8202,7294,8855,6469,3145,9592,9512,1023,7338,9063,6867,1951,1008,5821,6774,9383,1572,4669,4101,2140,9015,8936,5558,5485,9518,4022,1434,2522,5660,8094,2552,2421,3551,9682,523,3555,8935,5651,1893,8089,5999,9293,3444,5526,2592,8155,9722,2483,1030,332,5842,8261,2927,3442,5220,252,1302,6239,9135,649,8391,4161,5258,757,313,2049,2661,2069,228,8104,3308,8442,9217,3426,3796,4097,2325,4401,6676,4071,4437,9523,7100,1878,9532,6921,1248,8533,5997,3480,8594,3591,7603,9362,4166,5431,1263,6285,7248,2227,4868,3197,7263,2483,9015,6368,6416,1795,4032,960,1270,2784,5660,5169,1571,2343,6595,9823,3190,1682,9927,1615,9915,5499,9865,4028,7109,6996,6251,1857,9550,7481,1998,826,883,1949,2116,2569,6482,3902,5810,4060,8579,5783,7257,2510,8273,9645,5117,8730,3773,1346,6957,6847,8699,4185,5050,599,8541,1618,156,8906,3487,7346,4296,501,2026,6158,5610,3,4015,3338,6859,7216,6208,6002,6573,8511,229,748,3520,2898,9356,8579,5290,3788,8371,281,9159,5451,6284,3083,290,4818,3178,460,8419,7414,4241,5198,1402,8243,8674,4355,6351,2717,1981,1183,7540,5449,3027,784,5704,1981,3203,9183,1819,7157,8106,7389,5864,5498,8142,7126,3448,3622,9127,3571,1383,7756,7797,9477,1885,9112,3827,8988,2619,838,9394,4896,6516,5701,5442,5902,4931,4506,2366,5315,3214,9289,4042,9976};
    cout << A.size() << endl;
    k = 248;
    cout << s.maximumScore(A, k) << endl;
    return 0;
}
