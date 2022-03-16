#include <bits/stdc++.h>
using namespace std;
// clang-format off
int __fastio = []() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(0); return 0; } ();
#ifdef LOCAL_DEBUG
#include <competitive.h>
#else
#define pp(...)
#define ppp(...)
#endif
// clang-format on

/*
单调队列:
  可以在O(n)时间内维护滑动窗口内的最大/最小值
 */

const int maxn = 1e5;
int N, D;

struct xy {
  int x, y;
  bool operator<(const xy &other) const { return x < other.x; }
} A[maxn];

int mxq[maxn], mnq[maxn];
int mxl, mxr, mnl, mnr;

void solve() {
  mxl = mnl = 0;
  mxr = mnr = -1;
  cin >> N >> D;
  for (int i = 0; i < N; ++i) cin >> A[i].x >> A[i].y;
  sort(A, A + N);
  int res = INT32_MAX;
  int L = 0;                     // 窗口左端
  for (int i = 0; i < N; ++i) {  // 窗口右端
    // 单调递减, 队头为最大元素, 从队尾弹小于等于当前的元素
    while (mxl <= mxr && A[i].y >= A[mxq[mxr]].y) --mxr;
    mxq[++mxr] = i;
    // 单调递增, 队头为最小元素, 从队尾弹大于等于当前的元素
    while (mnl <= mnr && A[i].y <= A[mnq[mnr]].y) --mnr;
    mnq[++mnr] = i;
    while (L <= i && A[mxq[mxl]].y - A[mnq[mnl]].y >= D) {  // 滑动窗口
      res = min(res, A[i].x - A[L].x);
      ++L;
      // 窗口外元素出队
      while (mxl <= mxr && mxq[mxl] < L) ++mxl;
      while (mnl <= mnr && mnq[mnl] < L) ++mnl;
    }
  }
  if (res == INT32_MAX)
    cout << -1 << endl;
  else
    cout << res << endl;
}

int main() {
#ifdef LOCAL_DEBUG
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  int T0;
  cin >> T0;
  for (int t0 = 1; t0 <= T0; ++t0) {
    cout << "--------" << t0 << "--------\n";
#endif
    int T = 1;
    while (T--) {
      solve();
    }
#ifdef LOCAL_DEBUG
  }
#endif
  return 0;
}
