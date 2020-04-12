#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

// UNION FIND
// ref: 有一种算法叫做“Union-Find”？
// https://www.cnblogs.com/SeaSky0606/p/4752941.html
class Solution {
 private:
  vector<int> id;
  int count, n;

  //   int F(int x) { return id[x]; }

  //   void U(int p, int q) {
  //     int pID = F(p), qID = F(q);
  //     for (int i = 1; i <= n; ++i) {
  //       if (F(i) == pID) id[i] = qID;
  //     }
  //     --count;
  //   }

  int F(int x) {
    while (id[x] != x) x = id[x];
    return x;
  }

  void U(int p, int q) {
    int pID = F(p), qID = F(q);
    if (pID == qID) return;
    id[qID] = pID;
    --count;
  }

  bool connected(int p, int q) { return F(p) == F(q); }

 public:
  vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
    n = edges.size();
    count = n;
    id.clear();
    id.resize(n + 1, 0);
    // first find if any node's in-degree is 2
    vector<int> res, res1;
    for (auto& edge : edges) {
      if (++id[edge[1]] > 1) {
        res = edge;
        break;  // res could be edge, or the other edge2 (edge2[1] == edge[1])
      }
    }
    iota(id.begin(), id.end(), 0);

    if (res.empty()) {
      for (auto& edge : edges) {
        if (connected(edge[0], edge[1])) return edge;
        U(edge[0], edge[1]);
      }
    }

    for (auto& edge : edges) {
      if (edge[1] == res[1]) {
        if (edge[0] == res[0]) continue;
        res1 = edge;
      }
      if (connected(edge[0], edge[1])) {
        res = res1;
        break;
      }
      U(edge[0], edge[1]);
    }
    return res;
  }
};