#include <iostream>
#include <queue>

using namespace std;

// Allocation (5pts, 7pts)

void solve(int case_num) {
  int N, B, t;
  scanf("%d%d", &N, &B);
  priority_queue<int> q;
  for (int i = 0; i < N; ++i) {
    scanf("%d", &t);
    q.push(t);
    B -= t;
    if (B < 0) {
      B += q.top();
      q.pop();
    }
  }
  printf("Case #%d: %u\n", case_num, q.size());
}

int main(int argc, char const *argv[]) {
  int T;
  cin >> T;
  for (int i = 1; i <= T; ++i) {
    solve(i);
  }
  return 0;
}
