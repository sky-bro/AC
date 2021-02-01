#include <bits/stdc++.h>
using namespace std;

// space: O(4*n)

// update: increment every elements in a range by v
// unverified
class SegTree {
 private:
  int n;
  vector<int> t, t2;
  void build(vector<int> &nums, int p, int l, int r) {
    if (l == r) {
      t[p] = nums[l];
      return;
    }
    int mid = (l + r) >> 1;
    build(nums, p << 1, l, mid);
    build(nums, p << 1 | 1, mid + 1, r);
    t[p] = t[p << 1] + t[p << 1 | 1];
  }

 public:
  SegTree(vector<int> &nums)
      : n(nums.size()), t(n << 2), t2(n << 2, 0) /* no lazy info */ {
    build(nums, 1, 0, n - 1);  // nums start from  index 0?
  }

  void push(int p, int l, int r, int mid) {
    if (t2[p]) {
      t2[p << 1] += t2[p];
      t2[p << 1 | 1] += t2[p];
      t[p << 1] += t2[p] * (mid - l + 1);
      t[p << 1 | 1] += t2[p] * (r - mid);
      t2[p] = 0;
    }
  }
  void update(int p, int l, int r, int x, int y, int v) {
    if (x <= l && r <= y) {
      t2[p] += v;
      t[p] += (r - l + 1) * v;
      return;
    }
    int mid = (l + r) >> 1;
    push(p, l, r, mid);
    if (x <= mid) update(p << 1, l, mid, x, y, v);
    if (y > mid) update(p << 1 | 1, mid + 1, r, x, y, v);
    t[p] = t[p << 1] + t[p << 1 | 1];
  }
  int query(int p, int l, int r, int x, int y) {
    if (x <= l && r <= y) return t[p];
    int mid = l + r >> 1, res = 0;
    push(p, l, r, mid);
    if (x <= mid) res += query(p << 1, l, mid, x, y);
    if (y > mid) res += query(p << 1 | 1, mid + 1, r, x, y);
    return res;
  }
};

// update: assign every elements in a range as v (v!=-1, so we use -1 to
// initialize t2) verified
class SegTree2 {
 private:
  int n;
  vector<int> t, t2;
  void build(vector<int> &nums, int p, int l, int r) {
    if (l == r) {  // leaf
      t[p] = nums[l];
      return;
    }
    int mid = (l + r) >> 1;
    build(nums, p << 1, l, mid);
    build(nums, p << 1 | 1, mid + 1, r);
    t[p] = t[p << 1] + t[p << 1 | 1];
  }

 public:
  SegTree2(vector<int> &nums)
      : n(nums.size()), t(n << 2), t2(n << 2, -1) /* no lazy info */ {
    build(nums, 1, 0, n - 1);  // nums start from  index l = 0, ends at r = n-1
  }

  void push(int p, int l, int r, int mid) {
    if (~t2[p]) {
      t2[p << 1] = t2[p];
      t2[p << 1 | 1] = t2[p];
      t[p << 1] = t2[p] * (mid - l + 1);
      t[p << 1 | 1] = t2[p] * (r - mid);
      t2[p] = -1;
    }
  }
  void update(int p, int l, int r, int x, int y, int v) {
    if (x <= l && r <= y) {
      t2[p] = v;
      t[p] = (r - l + 1) * v;
      return;
    }
    int mid = (l + r) >> 1;
    push(p, l, r, mid);
    if (x <= mid) update(p << 1, l, mid, x, y, v);
    if (y > mid) update(p << 1 | 1, mid + 1, r, x, y, v);
    t[p] = t[p << 1] + t[p << 1 | 1];
  }
  int query(int p, int l, int r, int x, int y) {
    if (x <= l && r <= y) return t[p];
    int mid = l + r >> 1, res = 0;
    push(p, l, r, mid);
    if (x <= mid) res += query(p << 1, l, mid, x, y);
    if (y > mid) res += query(p << 1 | 1, mid + 1, r, x, y);
    return res;
  }
};
