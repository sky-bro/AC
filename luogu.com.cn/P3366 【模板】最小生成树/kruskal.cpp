#include <bits/stdc++.h>
using namespace std;
int __fastio = []() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } ();

const int N = 5e3, M = 2e5;

int n, m;
int ids[N];
struct Edge {
    int x, y, z;
    bool operator<(Edge &rhs) const {
        return z < rhs.z;
    }
} edges[M];

int F(int x) {
    return( x == ids[x]) ? x : (ids[x] = F(ids[x]));
}

void U(int x, int y) {
    ids[F(x)] = ids[F(y)];
}

void solve() {
    sort(edges, edges + m);
    iota(ids, ids+n, 0);
    int res = 0;
    int cnt = 0;
    for (int i = 0; i < m; ++i) {
        if (F(edges[i].x) != F(edges[i].y)) {
            U(edges[i].x, edges[i].y);
            res += edges[i].z;
            ++cnt;
        }
    }
    if (cnt != n - 1) cout << "orz\n";
    else cout << res << endl;
}

int main(int argc, char const *argv[]) {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].x >> edges[i].y >> edges[i].z;
        --edges[i].x;
        --edges[i].y;
    }
    solve();
    return 0;
}
