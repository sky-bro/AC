#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
 private:
  int n, groups;
  vector<int> ids;
  void U(int p, int q) {
    int pID = F(p), qID = F(q);
    if (pID != qID) {
      ids[qID] = pID;
      --groups;
    }
  }

  int F(int x) {
    int r = x;
    while (r != ids[r]) {
      r = ids[r];
    }

    while (x != r) {
      int t = ids[x];
      ids[x] = r;
      x = t;
    }
    return r;
  }

 public:
  int numSimilarGroups(vector<string>& A) {
    groups = n = A.size();
    int len = A[0].size();
    ids.clear();
    ids.resize(n);
    iota(ids.begin(), ids.end(), 0);
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        int diff = 0;
        for (int k = 0; k < len; ++k) {
          if (A[i][k] != A[j][k] && ++diff > 2) break;
        }
        if (diff <= 2) U(i, j);
      }
    }
    return groups;
  }
};
