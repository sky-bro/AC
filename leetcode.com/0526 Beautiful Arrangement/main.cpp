#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 private:
  vector<unordered_map<int, int>> dp;
  int n;
  int dfs(int i, int visited) {
    if (i == 0) return 1;
    if (dp[i].count(visited)) return dp[i][visited];
    int res = 0;
    for (int ii = 1; ii <= n; ++ii) {
      if ((1 << ii) & visited) continue;
      if ((i % ii) && (ii % i)) continue;
      res += dfs(i - 1, visited | (1 << ii));
    }
    return dp[i][visited] = res;
  }

 public:
  int countArrangement(int N) {
    n = N;
    dp.clear();
    dp.resize(n + 1);
    return dfs(n, 0);
  }
};

int main(int argc, char const *argv[]) {
  int N;
  Solution s;

  while (cin >> N) {
    cout << s.countArrangement(N) << endl;
  }
  return 0;
}
