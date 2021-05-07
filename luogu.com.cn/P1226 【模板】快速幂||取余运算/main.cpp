#include <bits/stdc++.h>
using namespace std;
int __fastio = []() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } ();

template <typename T>
T fpow(T x, int n, T M) {
    T ret = 1;
    while (n) {
        if (n & 1) ret = ret * x % M;
        x = x * x % M;
        n >>= 1;
    }
    return ret % M;
}

typedef long long ll;

void solve() {
    ll b, p, k;
    cin >> b >> p >> k;
    cout << b << "^" << p << " mod " << k << "=" << fpow(b, p, k) << endl;
}

int main(int argc, char const *argv[]) {
    solve();
    return 0;
}
