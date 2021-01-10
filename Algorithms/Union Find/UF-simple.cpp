#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class UF {
 private:
  vector<int> ids;

 public:
  UF(int n) {
    ids.resize(n);
    iota(ids.begin(), ids.end(), 0);
  }

  int F(int x) { return ids[x] == x ? x : (ids[x] = F(ids[x])); }

  void U(int p, int q) { ids[F(p)] = ids[F(q)]; }
};
