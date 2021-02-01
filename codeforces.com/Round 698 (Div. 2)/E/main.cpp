#include <bits/stdc++.h>

using namespace std;

static int x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}();
typedef long long ll;

class SegTree2 {
 private:
  int n;
  vector<int> t, t2;
  void build(string &nums, int p, int l, int r) {
    if (l == r) {  // leaf
      t[p] = nums[l] - '0';
      return;
    }
    int mid = (l + r) >> 1;
    build(nums, p << 1, l, mid);
    build(nums, p << 1 | 1, mid + 1, r);
    t[p] = t[p << 1] + t[p << 1 | 1];
  }

 public:
  SegTree2(string &nums)
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

// just greedy, from f to s, simple
// but need segment tree, lazy propagation
bool run_case() {
  string s, f;
  int n, q;
  cin >> n >> q >> s >> f;
  vector<pair<int, int>> Q(q);
  for (int i = q - 1; i >= 0; --i) {
    cin >> Q[i].first >> Q[i].second;
  }
  SegTree2 t(f);
  for (auto &p : Q) {
    int sum = t.query(1, 0, n - 1, p.first - 1, p.second - 1);
    if (sum * 2 == p.second - p.first + 1) return false;
    t.update(1, 0, n - 1, p.first - 1, p.second - 1,
             sum * 2 > p.second - p.first + 1);
  }
  for (int i = 0; i < n; ++i) {
    if (t.query(1, 0, n - 1, i, i) != s[i] - '0') return false;
  }
  return true;
}

int main(int argc, char const *argv[]) {
  int T;
  cin >> T;
  while (T--) {
    cout << (run_case() ? "YES" : "NO") << endl;
  }
  return 0;
}
