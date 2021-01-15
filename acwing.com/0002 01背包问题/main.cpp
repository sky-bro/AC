#include <bits/stdc++.h>

using namespace std;

static int x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}();
typedef long long ll;

int N, V;

int solve(vector<pair<int, int>> &A) {
  vector<int> dp(V + 1);
  for (auto &p : A) {
    for (int v = V; v >= p.first; --v) {
      dp[v] = max(dp[v], dp[v - p.first] + p.second);
    }
  }
  return *max_element(dp.begin(), dp.end());
}

int main(int argc, char const *argv[]) {
  cin >> N >> V;  // volume
  vector<pair<int, int>> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i].first >> A[i].second;  // (weight, value)... not (value, weight)
  }
  cout << solve(A) << endl;
  return 0;
}
