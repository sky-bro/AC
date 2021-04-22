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

// TODO: change to template, iterator

/**
 * A simple and popular but slow algorithm, commonly known as Algorithm R
 * time complexity O(n)
 */
void reservoir_sample(vector<int> &S, vector<int> &R, int k) {
    R.resize(k);
    copy(S.begin(), S.begin()+k, R.begin());
    for (int i = k, n = S.size(); i < n; ++i) {
        int j = rand_int(0, i);
        if (j < k) R[j] = S[i]; // choose ith with probability (k/(i+1))
                                // keep ith with
                                // probability not being swapped by remmaing elements [i+1...n-1]
                                // (k/(i+1)) * (1-1/(i+2))*...*(1-1/n) = k/n
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

