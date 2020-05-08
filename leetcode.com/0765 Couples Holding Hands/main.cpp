#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
private:
  int n, cnt;
  vector<int> ids;
  int F(int x) {
    while (ids[x] != x) x = ids[x];
    return x;
  }
  void U(int p, int q) {
    int pID = F(p), qID = F(q);
    if (pID == qID) return;
    ids[pID] = qID;
    --cnt;
  }
  
public:
    int minSwapsCouples(vector<int>& row) {
      n = row.size();
      cnt = n/2;
      ids.resize(n);
      iota(ids.begin(), ids.end(), 0);
      for (int i = 1; i < n; i += 2) ids[i] = i-1;
      for (int i = 1; i < n; i += 2) U(row[i], row[i-1]);
      return n/2 - cnt;
    }
};
