#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int totalFruit(vector<int>& tree) {
    int t1 = tree[0], t2 = -1, idx = 1, n = tree.size();
    while (idx < n && tree[idx] == t1) ++idx;
    int res = idx, cur = idx;
    for (int i = idx; i < n; idx = i) {
      t2 = tree[idx];
      while (i < n && tree[i] == t2) ++i;
      cur += i - idx;
      res = max(cur, res);
      if (i < n) {
        if (tree[i] != t1) {
          cur = i - idx;
        }
        t1 = t2;
      } else
        break;
    }
    return res;
  }
};
