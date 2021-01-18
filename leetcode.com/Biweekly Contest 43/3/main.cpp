#include <bits/stdc++.h>

using namespace std;

static int x = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}();
typedef long long ll;

class Solution {
 private:
  vector<int> res;
  vector<bool> vis;
  int n;
  bool dfs(int idx) {
    while (idx < n * 2 - 1 && res[idx]) ++idx;
    if (idx == n * 2 - 1) return true;
    for (int i = n; i > 1; --i) {
      if (vis[i]) continue;
      if (idx + i < n * 2 - 1 && res[idx + i] == 0) {
        vis[i] = true;
        res[idx] = res[idx + i] = i;
        if (dfs(idx + 1)) return true;
        vis[i] = false;
        res[idx] = res[idx + i] = 0;
      }
    }
    if (vis[1] == false) {
      vis[1] = true;
      res[idx] = 1;
      if (dfs(idx + 1)) return true;
      res[idx] = 0;
      vis[1] = false;
    }
    return false;
  }

 public:
  vector<int> constructDistancedSequence(int n) {
    this->n = n;
    res.resize(2 * n - 1);
    fill(res.begin(), res.end(), 0);
    vis.resize(n + 1);
    fill(vis.begin(), vis.end(), false);
    dfs(0);
    return res;
  }
};

template <typename T>
void printArr(const vector<T> &arr) {
  for (const T &t : arr) cout << t << " ";
  cout << endl;
}

int main(int argc, char const *argv[]) {
  Solution s;
  int n;
  while (cin >> n) {
    auto res = s.constructDistancedSequence(n);
    printArr(res);
  }
  return 0;
}
