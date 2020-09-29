#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxDistToClosest(vector<int>& seats) {
    int res = 0, i = 0, n = seats.size();
    while (seats[i] == 0) {
      ++i;
      ++res;
    }
    int tmp_res = 0;
    while (seats[n - 1] == 0) {
      --n;
      ++tmp_res;
    }
    res = max(res, tmp_res);
    while (i < n - 1) {
      ++i;
      int len = 0;
      while (seats[i] == 0) {
        ++i;
        ++len;
      }
      res = max(res, (len + 1) / 2);
    }
    return res;
  }
};
