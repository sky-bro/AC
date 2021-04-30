#include <bits/stdc++.h>
using namespace std;

default_random_engine generator;

/**
 * get uniformly distributed random int from [lo...hi]
 */
int rand_int(int lo, int hi) {
    uniform_int_distribution<int> distribution(lo, hi);
    return distribution(generator);
}

/**
 * use three way partition
 * T(n) = 2T(n/2) + n
*/
void qsort(vector<int>& A, int l, int r) {
    if (l >= r) return;
    int i = rand_int(l, r);
    int x = A[i], lo = l, hi = r;
    i = l;
    while (i <= hi) {
        if (A[i] == x) ++i;
        else if (A[i] < x) swap(A[i++], A[lo++]);
        else swap(A[i], A[hi--]);
    }
    qsort(A, l, lo - 1);
    qsort(A, hi + 1, r);
}
