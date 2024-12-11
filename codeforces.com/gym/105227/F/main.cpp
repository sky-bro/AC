#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n, x;
    cin >> n;
    vector<int> distance(n+1), prev(n+1), result(n+1, -1);
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        if (distance[x] == 0) {
            distance[x] = i;
            prev[x] = i;
            continue;
        }
        distance[x] = max(distance[x], i - prev[x]);
        prev[x] = i;
    }
    for (int i = 1; i <= n; ++i) {
        if (distance[i] == 0) continue;
        int d = max(n - prev[i] + 1, distance[i]);
        for (; d <= n && result[d] == -1; ++d) {
            result[d] = i;
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
    return 0;
}
