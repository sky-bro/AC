#include <cmath>
#include <iostream>
#include <queue>

using namespace std;

void solve(int case_num) {
  int N, K;
  scanf("%d%d", &N, &K);
  priority_queue<pair<double, int>> q;
  double pre;
  scanf("%lf", &pre);
  for (int i = 1; i < N; ++i) {
    double cur;
    scanf("%lf", &cur);
    q.push(make_pair(cur - pre, 1));
    pre = cur;
  }
  for (int i = 0; i < K; ++i) {
    auto p = q.top();
    q.pop();
    if (abs(p.first - 1) < 1e-5) {
      printf("Case #%d: %d\n", case_num, 1);
      return;
    }
    q.push(make_pair(p.first * p.second / (1 + p.second), 1 + p.second));
  }
  printf("Case #%d: %d\n", case_num, int(ceil(q.top().first)));
}

int main(int argc, char const *argv[]) {
  int T;
  scanf("%d", &T);
  for (int i = 1; i <= T; ++i) {
    solve(i);
  }
  return 0;
}
