#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
 * find the k-th (smallest) element of arr (k in [0..arr.size()-1])
 * e.g. the 3-th (smallest) element of {5,4,3,2,1,0} 3
 *
 * <Lomuto partition scheme>
 */
int quickSelect(vector<int> &arr, int l, int r, int k) {
  if (l == r) return arr[l];
  int ll = l, pivot = arr[r];
  for (int i = l; i < r; ++i) {
    if (arr[i] < pivot) {
      swap(arr[i], arr[ll++]);
    }
  }
  swap(arr[ll], arr[r]);
  // arr is like: ----(arr[ll]/pivot)++++, smaller ones on the left
  if (ll == k)
    return arr[k];
  else
    return ll < k ? quickSelect(arr, ll + 1, r, k)
                  : quickSelect(arr, l, ll - 1, k);
}

/**
 * find the k-th (smallest) element of arr (k in [0..arr.size()-1])
 * e.g. the 3-th (smallest) element of {5,4,3,2,1,0} 3
 *
 * <Hoare partition scheme>
 */
int quickSelect2(vector<int> &arr, int l, int r, int k) {
  if (l == r) return arr[l];
  int pivot = arr[(l + r) / 2];
  int ll = l - 1, rr = r + 1;
  while (true) {
    do
      ++ll;
    while (arr[ll] < pivot);
    do
      --rr;
    while (arr[rr] > pivot);
    if (ll >= rr) break;
    swap(arr[ll], arr[rr]);
  }
  // arr is like: ----++++, but the pivot index is unknown
  if (ll <= k)
    return quickSelect2(arr, ll, r, k);
  else
    return quickSelect2(arr, l, ll-1, k);
}

int main(int argc, char const *argv[]) {
  vector<int> arr{3, 2, 4, 5, 1};  // {1, 2, 3, 4, 5}
  int k = 3;

  // Lomuto partition scheme
  cout << quickSelect(arr, 0, arr.size() - 1, k - 1) << endl;  // 3

  // Hoare partition scheme
  cout << quickSelect2(arr, 0, arr.size() - 1, k - 1) << endl;  // 3

  nth_element(arr.begin(), arr.begin() + k - 1, arr.end());
  cout << *(arr.begin() + k - 1) << endl;  // 3

  return 0;
}
