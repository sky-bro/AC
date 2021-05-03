#include <bits/stdc++.h>
using namespace std;
int __fastio = []() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } ();

int n, m;
const int N = 1e8+1;
int primes[N];
bool sifted[N];

void solve() {
    int sz = 0;
    for (int i = 2; i <= n; ++i) {
        if (!sifted[i]) primes[sz++] = i;
        for (int j = 0; j < sz && i * primes[j] <= n; ++j) {
            sifted[i * primes[j]] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

int main(int argc, char const *argv[]) {
    cin >> n >> m;
    solve();
    while (m--) {
        int j;
        cin >> j;
        cout << primes[j - 1] << endl;
    }
    return 0;
}
