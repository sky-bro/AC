#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;

// PRNG
random_device rd;
mt19937 g(rd());
// default_random_engine g;
/**
 * @returns a random number inside [l, r]
 */
size_t rand_idx(size_t l, size_t r) {
    uniform_int_distribution<size_t> dis(l, r);
    return dis(g);
}

// blog: https://k4i.top/en/posts/shuffling/

template <typename T>
void printArr(const vector<T> &arr) {
    for (const T &t : arr) cout << t << " ";
    cout << endl;
}

// Fisher-Yates shuffle, clang's libc++ uses this version
template <typename T>
void fisher_yates_shuffle(vector<T> &A) {
    for (int i = A.size() - 1; i > 0; --i) {
        swap(A[rand_idx(0, i)], A[i]);
    }
}

// Fisher-Yates shuffle, from left to right
template <typename T>
void fisher_yates_shuffle2(vector<T> &A) {
    int n = A.size();
    for (int i = 0; i < n - 1; ++i) {
        swap(A[rand_idx(i, n - 1)], A[i]);
    }
}

// The "inside-out" shuffle
template <typename T>
void inside_out_shuffle(vector<T> &A) {
    int n = A.size();
    for (int i = 1; i < n; ++i) {
        swap(A[rand_idx(0, i)], A[i]);
    }
}

int main(int argc, char const *argv[])
{
    vector<int> A(10);
    iota(A.begin(), A.end(), 0);
    // shuffle(A.begin(), A.end(), g);
    // fisher_yates_shuffle(A);
    // fisher_yates_shuffle2(A);
    inside_out_shuffle(A);
    
    printArr(A);
    return 0;
}
