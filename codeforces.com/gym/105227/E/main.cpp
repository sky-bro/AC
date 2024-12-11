#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int MAX = 1e6;

vector<vector<int>> Xs(10, vector<int>());
vector<int> allG(MAX+1);

int g(int x) {
    if (x < 10) {
        return x;
    }
    int y = 1;
    while (x) {
        y *= (x%10);
        x /= 10;
    }
    return g(x);
}

void init() {
    for (int i = 1; i <= 9; ++i) {
            Xs[i].push_back(i);
            allG[i] = i;
    }
    for (int i = 10; i <= MAX; ++i) {
        int y = 1, x = i;
        for (; x; x /= 10) {
            if (x % 10 == 0) continue;
            y *= (x % 10);
        }
        allG[i] = allG[y];
        Xs[allG[i]].push_back(i);
    }
}

int main(int argc, char const *argv[])
{
    init();
    int n, l, r, k;
    cin >> n;
    while (n--) {
        cin >> l >> r >> k;
        vector<int> &X = Xs[k];
        auto left = lower_bound(X.begin(), X.end(), l);
        auto right = upper_bound(X.begin(), X.end(), r);
        cout << right - left << endl;
    }
    return 0;
}
