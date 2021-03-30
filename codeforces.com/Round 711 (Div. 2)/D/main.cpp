#include <bits/stdc++.h>
using namespace std;
int __fastio = []() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } ();

typedef long long ll;

const int N = 1e5;
const double EPS = 1.0*(N-1)/N;
#define UP(x) ll(x + EPS)
int n, m;
int t, y;
double x;

int res[N+1];
void solve() {
    memset(res + 1, -1, sizeof(int) * (m+1));
    for (int i = 1; i <= n; ++i) {
        cin >> t >> x >> y;
        x/=N;
        for (int j = m; j >= 0; --j) {
            if (res[j] == -1) continue;
            ll ii = j;
            for (int k = 1; k <= y; ++k) {
                if (t == 1) ii = UP(ii + x);
                else ii = UP(ii*x);
                if (ii > m || ~res[ii]) break;
                res[ii] = i;
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    cin >> n >> m;
    solve();
    for (int i = 1; i <= m; ++i) cout << res[i] << " ";
    cout << endl;
    return 0;
}
