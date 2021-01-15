#include <bits/stdc++.h>

using namespace std;

static int x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}();
typedef long long ll;

int N, V;

int solve(vector<int> &weights, vector<int> &values, vector<int> &nums) {
  vector<int> dp(V + 1);
  for (int i = 0; i < N; ++i) {
    int num = min(nums[i], V / weights[i]);
    for (int k = 1; num; k *= 2) {
      if (k > num) k = num;
      num -= k;
      for (int j = V; j >= weights[i] * k; --j) {
        dp[j] = max(dp[j], dp[j - weights[i] * k] + values[i] * k);
      }
    }
  }
  return dp[V];
}

int main(int argc, char const *argv[]) {
  cin >> N >> V;  // volume
  vector<int> weights(N), values(N), nums(N);
  for (int i = 0; i < N; ++i) {
    cin >> weights[i] >> values[i] >>
        nums[i];  // (weight, value)... not (value, weight)
  }
  cout << solve(weights, values, nums) << endl;
  return 0;
}
