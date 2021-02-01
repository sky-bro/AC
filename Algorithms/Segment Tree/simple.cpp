#include <bits/stdc++.h>

using namespace std;

// iterative segment tree
// space: O(2*n)
// time to update an element:  O(logn)
// time to update a range of size m:  O(mlogn)
// time to query a range: O(logn)

class SegTree {
 private:
  int n;
  vector<int> t;

 public:
  SegTree(vector<int>& nums) : n(nums.size()), t(2 * n) {
    for (int i = 0; i < n; ++i) t[i + n] = nums[i];
    for (int i = n - 1; i > 0; --i) t[i] = t[i << 1] + t[i << 1 | 1];
  }
  void update(int i, int val) {
    i += n;
    if (t[i] == val) return;
    for (t[i] = val; i > 1; i >>= 1) t[i >> 1] = t[i] + t[i ^ 1];
  }
  int query(int i, int j) {  // sum range [i, j]
    int sum = 0;
    for (i += n, j += n + 1; i < j; i >>= 1, j >>= 1) {
      if (i & 1) sum += t[i++];
      if (j & 1) sum += t[--j];
    }
    return sum;
  }
};

int main(int argc, char const* argv[]) {
  int n = 6;
  vector<int> nums(n);
  iota(nums.begin(), nums.end(), 1);
  SegTree t(nums);
  cout << t.query(0, n - 1) << endl;
  return 0;
}
