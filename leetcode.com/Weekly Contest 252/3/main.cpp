#include <bits/stdc++.h>
using namespace std;
int __fastio = []() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } ();

typedef long long ll;
class Solution {
private:
    ll f(ll n) {
        return 2*n*(2*n+1)*(n+1);
    }
public:
    long long minimumPerimeter(long long x) {
        ll l = 1, r = 1e5;
        while (l < r) {
            ll m = (l + r) >> 1;
            if (f(m) >= x) r = m;
            else l = m + 1;
        }
        return l * 8;
    }
};
