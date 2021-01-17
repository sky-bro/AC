#include <bits/stdc++.h>

using namespace std;

static int x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}();
typedef long long ll;

// dfs + binary search: fast
class Solution {
 public:
  int minimumTimeRequired(vector<int>& jobs, int k) {
    int sum = 0;
    for (int j : jobs) sum += j;
    sort(jobs.begin(), jobs.end(), greater<int>());
    int l = jobs[0], r = sum;
    while (l < r) {
      int mid = (l + r) >> 1;
      vector<int> worker(k, 0);
      if (dfs(jobs, worker, 0, mid))
        r = mid;
      else
        l = mid + 1;
    }
    return l;
  }
  // f(n) = k*f(n-1) = k^n
  bool dfs(vector<int>& jobs, vector<int>& worker, int step, int target) {
    if (step >= jobs.size()) return true;
    int cur = jobs[step];
    // assign cur to worker i
    for (int i = 0; i < worker.size(); i++) {
      if (worker[i] + cur <= target) {
        worker[i] += cur;
        if (dfs(jobs, worker, step + 1, target)) return true;
        worker[i] -= cur;
      }
      if (worker[i] == 0) break;
    }
    return false;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> A = {1, 2, 4, 7, 8};
  int k = 2;
  // A = {5, 15, 4, 9, 15, 8, 8, 9};
  // k = 2;
  cout << s.minimumTimeRequired(A, k) << endl;
  return 0;
}
