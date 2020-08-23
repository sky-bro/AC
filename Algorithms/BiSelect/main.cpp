#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

/**
 * get the k-th element of L, 0 <= l <= k <= r < L.size() (index starts from 0)
 */
int pick(vector<int> &L, int l, int r, int k) {
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
  int median = pick(L, l, nr, (nr + l) / 2);

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
void biselect(vector<vector<int>> &A, vector<int> &index, int k1, int k2,
              int &x, int &y) {
  int n = index.size();
#define A(i, j) A[index[i]][index[j]]
  if (n <= 2) {
    vector<int> tmp;
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
  int a, b;
  biselect(A, index_, k1_, k2_, a, b);

  // merge / combine
  // compute ra_less, rb_more and L same time.
  int ra_less = 0, rb_more = 0;
  vector<int> L;
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
    x = pick(L, 0, L.size() - 1, k1 + rb_more - n * n - 1); // index starts from 0 in pick function
  // y
  if (ra_less <= k2 - 1)
    y = a;
  else if (k2 + rb_more - n * n <= 0)
    y = b;
  else
    y = pick(L, 0, L.size() - 1, k2 + rb_more - n * n - 1);
}

int main(int argc, char const *argv[]) {
  vector<vector<int>> A = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
  vector<int> index(A.size());
  iota(index.begin(), index.end(), 0);
  int k1 = 8, k2 = 8, x, y;
  biselect(A, index, k1, k2, x, y);
  cout << "x: " << x << ", y: " << y << endl;  // x: 13, y: 13
  return 0;
}
