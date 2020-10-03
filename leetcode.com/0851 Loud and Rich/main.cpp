#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
 private:
  int n;
  vector<int> res;
  int dfs(vector<vector<int>> &G, vector<int> &quiet, vector<bool> &vis,
          int i) {
    int y = i;
    for (int ni : G[i]) {
      if (vis[ni]) {
        if (quiet[y] > quiet[res[ni]]) {
          y = res[ni];
        }
      } else {
        int ty = dfs(G, quiet, vis, ni);
        if (quiet[y] > quiet[ty]) {
          y = ty;
        }
      }
    }
    return res[i] = y;
  }

 public:
  vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet) {
    n = quiet.size();
    vector<vector<int>> G(n);
    for (auto &vi : richer) {
      G[vi[1]].push_back(vi[0]);
    }
    res.clear();
    res.resize(n);
    iota(res.begin(), res.end(), 0);
    vector<bool> vis(n);
    for (int i = 0; i < n; ++i) {
      if (vis[i] == false) {
        vis[i] = true;
        dfs(G, quiet, vis, i);
      }
    }
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
  vector<vector<int>> richer = {{0, 1}};
  vector<int> quiet = {1, 2, 0};
  printArr(s.loudAndRich(richer, quiet));
  return 0;
}
