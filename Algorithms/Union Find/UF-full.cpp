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

  int F(int x) { return ids[x] == x ? x : (ids[x] = F(ids[x])); }

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
