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
 * get uniformly distributed real number from [lo, hi)
 */
double rand_real(double lo, double hi) {
    uniform_real_distribution<double> distribution(lo, hi);
    return distribution(generator);
}

// TODO: change to template, iterator

/**
 * Algorithm L improves upon this algorithm by
 * computing how many items are discarded before
 * the next item enters the reservoir
 * time complexity O(k(1+log(n/k)))
 */
void reservoir_sample(vector<int> &S, vector<int> &R, int k) {
    R.resize(k);
    copy(S.begin(), S.begin()+k, R.begin());
    double W = exp(log(rand_real(0, 1))/k);
    for (int i = k, n = S.size(); i < n;) {
        i += floor(log(rand_real(0, 1))/log(1-W)) + 1;
        if (i < n) {
            R[rand_int(0, k-1)] = S[i];
            W *= exp(log(rand_real(0, 1))/k);
        }
    }
}

int main(int argc, char const *argv[])
{
    int n, k;
    while (cin >> n >> k) {
        if (n < k || k < 0) {
            cout << "wrong n, k: " << n << ", " << k << endl;
            continue;
        }

        vector<int> S(n);
        iota(S.begin(), S.end(), 0);
        vector<int> R;

        reservoir_sample(S, R, k);

        cout << "R:\n\t";
        for (auto &x: R) cout << x << " ";
        cout << endl;
    }
    return 0;
}

