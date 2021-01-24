#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 private:
  vector<int> ids;
  int n, groups;
  void U(int p, int q) {
    int pid = F(p), qid = F(q);
    if (pid != qid) {
      ids[pid] = qid;
      --groups;
    }
  }

  int F(int x) { return x == ids[x] ? x : ids[x] = F(ids[x]); }

 public:
  int removeStones(vector<vector<int>>& stones) {
    n = groups = stones.size();
    ids.resize(n);
    iota(ids.begin(), ids.end(), 0);
    unordered_map<int, int> row, col;
    for (int i = 0; i < n; ++i) {
      auto p = row.emplace(stones[i][0], i);
      if (!p.second) {
        U(p.first->second, i);
      }
      p = col.emplace(stones[i][1], i);
      if (!p.second) {
        U(p.first->second, i);
      }
    }
    return n - groups;
  }
};
