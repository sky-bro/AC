#include <bits/stdc++.h>
using namespace std;
int __fastio = []() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; } ();

const int N = 1e6;
int sz = 0;
// here is a max_heap, A[0] is the maximum value
int A[N];

void go_down(int i) {
    for (int j = 2 * i + 1; j < sz; j = 2 * (i = j) + 1) { // j: left child of i
        if (j < sz - 1 && A[j] < A[j + 1]) ++j; // go to right child
        if (A[i] >= A[j]) break;
        swap(A[i], A[j]);
    }
}

void go_up(int i) {
    for (int p = (i - 1) / 2; i; p = ((i = p) - 1) / 2) {
        if (A[i] <= A[p]) break;
        swap(A[i], A[p]);
    }
}

void heapify(int n) {
    if (n == 1) return;
    int i = (n - 2) / 2;
    while (true) {
        go_down(i);
        if (i-- == 0) return;
    }
}

void pop() {
    if (sz <= 1) {
        sz = 0;
        return;
    }
    swap(A[0], A[--sz]);
    go_down(0);
}

void push(int x) {
    A[sz] = x;
    go_up(sz++);
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    while (n--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x;
            cin >> x;
            push(-x);
        } else if (op == 2) {
            cout << -A[0] << endl;
        } else {
            pop();
        }
    }
    return 0;
}


