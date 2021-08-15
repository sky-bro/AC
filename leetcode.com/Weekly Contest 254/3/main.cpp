#include <bits/stdc++.h>
using namespace std;
int __fastio = []() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } ();

typedef unsigned long long ull;

template <typename T>
T fpow(T x, T n, ull MOD = 1e9+7) {
    T ret = 1;
    x %= MOD;
    while (n) {
        if (n & 1) ret = (ret * x) % MOD;
        x = (x * x) % MOD;
        n >>= 1;
    }
    return ret % MOD;
}

class Solution {
public:
    int minNonZeroProduct(int p) {
        if (p == 1) return 1;
        // p = 3, res = 
        // 001, 010, 011, 100, 101, 110, 111
        // p = 4
        // 0001, 0010, 0011, 0100, 0101, 0110, 0111, 1000, 1001, 1010, 1011, 1100, 1101, 1110, 1111
        //       0001 0001 1110 1110
        // 2 + 2 + 2
        // 1 + 1
        // 
        ull x = fpow<ull>(2ULL, p) - 1;
        ull m = 1e9+7;
        // return (fpow(x-1, x/2) * x) % m;
        // cout << "me: " << x/2 << endl;
        // cout << "ri: " << (1L << p - 1) - 1 << endl;
        return (int)(fpow<ull>(x-1, (1ULL << p - 1)-1) * x % m);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    ull n;
    while (cin>>n) {
        // cout << fpow(2ULL, n) << endl;
        cout << s.minNonZeroProduct(n) << endl;
    }
    return 0;
}

