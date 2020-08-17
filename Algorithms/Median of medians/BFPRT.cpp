#include "BFPRT.h"
#include <iostream>

using std::swap, std::min;

int partition5(int L[], int left, int right) {
  for (int i = left + 1; i <= right; ++i) {
    int j = i;
    while (j > left && L[j - 1] > L[j]) {
      swap(L[j - 1], L[j]);
      --j;
    }
  }
  return (left + right) / 2;  // return middle index (the median index)
}

void select(int L[], int left, int right, int k);

// the actual median-fo-medians algorithm
// return the pivot index
int pivot(int L[], int left, int right) {
  if (right - left < 5) return partition5(L, left, right);
  int n = right - left + 1;
  for (int i = left; i <= right; i += 5) {
    int sub_right = min(i + 4, right);
    int median5 = partition5(L, i, sub_right);
    swap(L[median5], L[left + (i - left) / 5]);
  }

  // approximate median index
  int mid = (right - left) / 10 + left + 1;  // wiki
  // int mid = (right - left) / 10 + left; // I think this is also ok.

  select(L, left, left + (right - left) / 5, mid);

  return mid;
}

// three way partition used in select, we need the k-th smallest in select
int partition(int L[], int left, int right, int pivot_index, int k) {
  int pivot_value = L[pivot_index];
  swap(L[pivot_index], L[right]);
  // ---[=]=[=]+++
  int store_index = left;
  for (int i = left; i < right; ++i) {
    if (L[i] < pivot_value) {
      swap(L[store_index++], L[i]);
    }
  }
  int store_index_eq = store_index;
  for (int i = store_index; i < right; ++i) {
    if (L[i] == pivot_value) {
      swap(L[store_index_eq++], L[i]);
    }
  }
  swap(L[right], L[store_index_eq]);
  if (k < store_index)
    return store_index;
  else if (k < store_index_eq)
    return k;
  else
    return store_index_eq;
}

// put k-th element at L[k] (0 indexed)
void select(int L[], int left, int right, int k) {
  while (true) {
    if (left == right) return;
    int pivot_index = pivot(L, left, right);
    pivot_index = partition(L, left, right, pivot_index, k);
    if (k == pivot_index)
      return;
    else if (k < pivot_index)
      right = pivot_index - 1;
    else
      left = pivot_index + 1;
  }
}
