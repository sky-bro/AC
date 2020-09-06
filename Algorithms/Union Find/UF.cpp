#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class UF {
 private:
  vector<int> ids, cnts;
  int cnt;

 public:
  UF(int n) {
    ids.resize(n);
    iota(ids.begin(), ids.end(), 0);
    cnt = n;
    cnts.resize(n, 1);
  }

  int F(int x) {
    int p = x;
    while (p != ids[p]) {
      p = ids[p];
    }

    // 优化，路径压缩，将x到根节点路径上所有节点的父亲（id）全部改成根节点
    int p2 = x;
    while (ids[p2] != p) {
      int next_p2 = ids[p2];
      ids[p2] = p;
      p2 = next_p2;
    }

    return p;
  }

  void U(int p, int q) {
    int pid = F(p), qid = F(q);
    if (pid != qid) {
      ids[qid] = pid;
      --cnt;
      cnts[pid] += cnts[qid];
    }
  }

  int group_count() { return cnt; }
  int count(int x) { return cnts[F(x)]; }
  bool connected(int p, int q) { return F(p) == F(q); }
};
