#include <iostream>
#include <vector>

using namespace std;

void solve(int case_num) {
  vector<int> arr;
  int N, num;
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    scanf("%d", &num);
    arr.push_back(num);
  }
  int res = 0;
  for (int i = 1; i < N - 1; ++i) {
    if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) ++res;
  }
  printf("Case #%d: %d\n", case_num, res);
}

int main(int argc, char const *argv[]) {
  int T;
  scanf("%d", &T);
  for (int i = 1; i <= T; ++i) {
    solve(i);
  }
  return 0;
}
