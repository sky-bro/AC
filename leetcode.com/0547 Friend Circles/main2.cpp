#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

// union find
class Solution {
 private:
  int n, cnt;
  vector<int> ids;
  void U(int p, int q) {
    int pid = F(p), qid = F(q);
    if (pid != qid) {
      --cnt;
      ids[pid] = ids[qid];
    }
  }
  int F(int x) { return x == ids[x] ? x : (ids[x] = F(ids[x])); }

 public:
  int findCircleNum(vector<vector<int>>& isConnected) {
    n = cnt = isConnected.size();
    ids.resize(n);
    iota(ids.begin(), ids.end(), 0);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (isConnected[i][j]) {
          U(i, j);
        }
      }
    }
    return cnt;
  }
};
