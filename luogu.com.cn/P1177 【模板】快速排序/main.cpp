#include <bits/stdc++.h>
using namespace std;
int __fastio = []() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } ();

// default_random_engine g;
random_device rd;
mt19937 g(rd());

int rand_int(int lo, int hi) {
    uniform_int_distribution<int> dist(lo, hi);
    return dist(g);
}

const int N = 1e5+1;
int A[N];
int n;

void qsort(int l, int r) {
    if (l >= r) return;
    int x = A[rand_int(l, r)];
    // cout << "pivot: " << x << endl;
    int lo = l, hi = r, i = l;
    while (i <= hi) {
        if (A[i] < x) {
            swap(A[i++], A[lo++]);
        } else if (A[i] > x) {
            swap(A[i], A[hi--]);
        } else {
            ++i;
        }
    }
    qsort(l, lo-1);
    qsort(hi+1, r);
}

int main(int argc, char const *argv[]) {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> A[i];
    qsort(0, n-1);
    for (int i = 0; i < n - 1; ++i) {
        cout << A[i] << " ";
    }
    cout << A[n-1];
    cout << endl;
    return 0;
}
