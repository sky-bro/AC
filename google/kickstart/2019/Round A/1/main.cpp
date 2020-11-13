#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 1e5;

int N, P;
int A[MAXN];

void solve(int case_num) {
  cin >> N >> P;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  sort(A, A + N);
  int cur = 0;
  for (int i = 1; i < P; ++i) cur += (A[i] - A[i - 1]) * i;
  int res = cur;
  for (int i = P; i < N; ++i) {
    cur += (A[i] - A[i - 1]) * P - A[i] + A[i - P];
    res = min(res, cur);
  }
  cout << res << "\n";
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(0);
  int T;
  cin >> T;
  for (int i = 1; i <= T; ++i) {
    cout << "Case #" << i << ": ";
    solve(i);
  }
  return 0;
}
