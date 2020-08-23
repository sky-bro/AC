#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

// ref: https://leetcode.com/problems/k-th-smallest-prime-fraction/discuss/115819/Summary-of-solutions-for-problems-%22reducible%22-to-LeetCode-378
// ref: https://leetcode.com/problems/k-th-smallest-prime-fraction/discuss/115545/O(n)
// needs optimize on the template, constructing too many struct is heavy

using namespace std;

struct Node {
  int a, b;
  double val;
  Node(int _a, int _b) : a(_a), b(_b), val(a * 1.0 / b) {}
  Node() {}
  bool operator<(const Node& other) const { return val < other.val; }
  bool operator>(const Node& other) const { return val > other.val; }
  bool operator>=(const Node& other) const { return val >= other.val; }
  bool operator<=(const Node& other) const { return val <= other.val; }
};

/**
 * get the k-th element of L, 0 <= l <= k <= r < L.size() (index starts from 0)
 */
template <typename T>
T pick(vector<T>& L, int l, int r, int k) {
  if (l == r) return L[l];

  // get median of medians
  for (int i = l; i <= r; i += 5) {
    int j = min(r, i + 5);
    for (int ii = i + 1; ii <= j; ++ii) {
      for (; ii > i && L[ii - 1] > L[ii]; --ii) swap(L[ii], L[ii - 1]);
    }
    swap(L[l + (i - l) / 5], L[(i + j) / 2]);
  }
  int nr = l + (r - l) / 5;
  T median = pick(L, l, nr, (nr + l) / 2);

  // three way partition with the approximate median
  // ---[=]=[=]+++
  //    low high
  int i = l, low = l, high = r;
  while (i <= high) {
    if (L[i] == median)
      ++i;
    else if (L[i] < median)
      swap(L[i++], L[low++]);
    else
      swap(L[i], L[high--]);
  }

  if (k < low) {
    return pick(L, l, low - 1, k);
  } else if (k <= high) {
    return L[k];
  } else {
    return pick(L, high + 1, r, k);
  }
}

/**
 * get k1-th and k2-th element of A, put k1-th element in x, k2-th element in y
 * index.size() >= k1 >= k2 >= 1 (index starts from 1)
 */
template <typename T>
void biselect(vector<vector<T>>& A, vector<int>& index, int k1, int k2, T& x,
              T& y) {
  int n = index.size();
#define A(i, j) A[index[i]][index[j]]
  if (n <= 2) {
    vector<T> tmp;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        tmp.push_back(A(i, j));
      }
    }
    sort(tmp.begin(), tmp.end());
    x = tmp[k1 - 1];
    y = tmp[k2 - 1];
    return;
  }

  // subproblem
  // divide
  vector<int> index_;
  for (int i = 0; i < n; i += 2) index_.push_back(index[i]);
  if ((n & 1) == 0) index_.push_back(index[n - 1]);
  int k1_ = n & 1 ? (k1 + 2 * n) / 4 + 1 : n + 1 + (k1 + 3) / 4;
  int k2_ = (k2 + 3) / 4;
  // conquer
  // k1_ >= k2_, a >= b
  T a, b;
  biselect(A, index_, k1_, k2_, a, b);

  // merge / combine
  // compute ra_less, rb_more and L same time.
  int ra_less = 0, rb_more = 0;
  vector<T> L;
  int ja = n, jb = n;
  for (int i = 0; i < n; ++i) {
    while (ja > 0 && A(i, ja - 1) >= a) --ja;
    ra_less += ja;
    while (jb > 0 && A(i, jb - 1) > b) --jb;
    rb_more += n - jb;
    //                  jb   ja
    // each row: ---bbb[x]xx[a]aa+++
    // append x's to L (b < x < a)
    for (int ii = jb; ii < ja; ++ii) L.push_back(A(i, ii));
  }

  // compute x, y
  // x
  if (ra_less <= k1 - 1)
    x = a;
  else if (k1 + rb_more - n * n <= 0)
    x = b;
  else
    x = pick(L, 0, L.size() - 1,
             k1 + rb_more - n * n - 1);  // index starts from 0 in pick function
  // y
  if (ra_less <= k2 - 1)
    y = a;
  else if (k2 + rb_more - n * n <= 0)
    y = b;
  else
    y = pick(L, 0, L.size() - 1, k2 + rb_more - n * n - 1);
}

class Solution {
 public:
  vector<int> kthSmallestPrimeFraction(vector<int>& arr, int K) {
    int n = arr.size();
    vector<vector<Node>> matrix(n, vector<Node>(n));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        matrix[i][j] = Node(arr[j], arr[n - 1 - i]);
      }
    }
    vector<int> index(n);
    iota(index.begin(), index.end(), 0);
    Node x, y;
    biselect(matrix, index, K, K, x, y);
    return {x.a, x.b};
  }
};
