#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
// clang-format off
#ifdef LOCAL_DEBUG
#include <competitive.h>
#else
#define pp(...)
#define ppp(...)
#endif
// clang-format on

int n, k;
const int maxn = 1e6;
int q[maxn], A[maxn];
int head, tail;

void getMin(bool (*cmp)(int, int)) {
  head = 0, tail = -1;
  for (int i = 0; i < n; ++i) {
    while (tail >= head && cmp(A[i], A[q[tail]])) {
      --tail;
    }
    q[++tail] = i;
    if (i >= k && q[head] == i - k) {
      ++head;
    }
    if (i >= k - 1) {
      printf("%d ", A[q[head]]);
    }
  }
}

bool cmpMin(int a, int b) { return a <= b; }
bool cmpMax(int a, int b) { return a >= b; }

void solve() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) scanf("%d", A + i);
  // for (int &x : A) cin >> x;
  if (k > n) return;
  // 垃圾poj, function不能用? lambda不能用?
  // getMin(A, [](int a, int b) { return a <= b; });
  getMin(cmpMin);
  printf("\n");
  getMin(cmpMax);
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
