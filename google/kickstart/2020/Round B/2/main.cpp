#include <iostream>
#include <vector>

using namespace std;

void solve(int case_num) {
  int N;
  long long D;
  scanf("%d%lld", &N, &D);
  vector<long long> arr(N);
  for (int i = 0; i < N; ++i) {
    scanf("%lld", &arr[i]);
  }
  for (int i = N - 1; i >= 0; --i) {
    D = D / arr[i] * arr[i];
  }
  printf("Case #%d: %lld\n", case_num, D);
}

int main(int argc, char const *argv[]) {
  int T;
  scanf("%d", &T);
  for (int i = 1; i <= T; ++i) {
    solve(i);
  }
  return 0;
}
